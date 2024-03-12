
import random
import sys
import threading
import time
import numpy as np
import cv2 as cv
import math
from threading import Thread
import queue
from concurrent.futures import ThreadPoolExecutor



def rotate(img_p, angle):
    height, widht = img_p.shape[:2]
    point = (widht//2, height//2)
    mat = cv.getRotationMatrix2D(point, angle, 1)
    return cv.warpAffine(img_p, mat, (widht, height))


class ThreadWithReturnValue(Thread):
    def __init__(self, group=None, target=None, name=None, args=(), kwargs=None, daemon=None):
        super().__init__(group=None, target=None, name=None, args=(), kwargs=None, daemon=None)
        self._return = None
        self._target = target
        self._args = args
        
    def run(self):
        # print(type(self._target))
        if self._target is not None:
            self._return = self._target(*self._args, **self._kwargs)
            # print(self._return)

    def join(self, *args):
        Thread.join(self, *args)
        return self._return


def show_result(inside_part_outside, inside, outside, alpha):
    inside_rotate = rotate(inside, -alpha)
    outside_rotate = rotate(outside, alpha)

    outside_rotate_inside = outside_rotate[xstart:xstart + rows_inside, ystart:ystart + cols_inside]
    dst = cv.add(outside_rotate_inside, inside_rotate)
    outside_rotate[xstart:xstart+rows_inside, ystart:ystart+cols_inside] = dst

    result = outside_rotate
    cv.imshow(f'Result {alpha}', result)


def rotate_and_check(inside, outside, alpha_start):
    alpha = alpha_start
    beta = alpha_start
    alpha_end = alpha_start + 44
    acc = 0  # для проверки 720 точек на соответствие не поворота!!!
    curr_sum = 0
    min_sum = 10**5
    res_alpha = 0
    outside_rotate = return_image = outside.copy()
    while alpha <= alpha_end:
        rOut = cols_inside//2+2
        rIn = cols_inside//2-1

        xCentr = cols_outside//2
        yCentr = rows_outside//2

        xOut = abs(int(math.cos(acc*math.pi/180)*rOut))
        yOut = abs(int(math.sin(acc*math.pi/180)*rOut))
        xIn = abs(int(math.cos(acc*math.pi/180)*rIn))
        yIn = abs(int(math.sin(acc*math.pi/180)*rIn))

        curPointXout1 = xCentr + xOut
        curPointYout1 = yCentr - yOut
        curPointXin1 = xCentr + xIn
        curPointYin1 = yCentr - yIn
        # print(f'Run proccess {1}')
        diffbtw2points1 = abs(int(outside_rotate[curPointYout1][curPointXout1]) - int(outside_rotate[curPointYin1][curPointXin1]))

        curPointXout2 = xCentr - xOut
        curPointYout2 = yCentr - yOut
        curPointXin2 = xCentr - xIn
        curPointYin2 = yCentr - yIn 
        # print(f'Run proccess {2}')
        diffbtw2points2 = abs(int(outside_rotate[curPointYout2][curPointXout2]) - int(outside_rotate[curPointYin2][curPointXin2]))

        curPointXout3 = xCentr - xOut
        curPointYout3 = yCentr + yOut
        curPointXin3 = xCentr - xIn
        curPointYin3 = yCentr + yIn
        # print(f'Run proccess {3}')
        diffbtw2points3 = abs(int(outside_rotate[curPointYout3][curPointXout3]) - int(outside_rotate[curPointYin3][curPointXin3]))
        
        curPointXout4 = xCentr + xOut
        curPointYout4 = yCentr + yOut
        curPointXin4 = xCentr + xIn
        curPointYin4 = yCentr + yIn 
        # print(f'Run proccess {4}')
        diffbtw2points4 = abs(int(outside_rotate[curPointYout4][curPointXout4]) - int(outside_rotate[curPointYin4][curPointXin4]))

        curr_sum += diffbtw2points1 + diffbtw2points2 + diffbtw2points3 + diffbtw2points4

        if acc == 360:
            acc = 0
            alpha += 0.5
            diffbtw2points1 = diffbtw2points2 = diffbtw2points3 = diffbtw2points4 = 0

            if curr_sum < min_sum:
                min_sum = curr_sum
                res_alpha = alpha
                # return_image = outside_rotate

            curr_sum = 0
            inside_rotate = rotate(inside, -alpha)
            outside_rotate = rotate(outside, alpha)

            tmp = outside_rotate[xstart:xstart + rows_inside, ystart:ystart + cols_inside]

            dst = cv.add(tmp.copy(), inside_rotate)
            outside_rotate[xstart:xstart+rows_inside, ystart:ystart+cols_inside] = dst

        acc += 1  # для проверки всех координат (360 точек для проверки)

    return res_alpha, min_sum


if __name__ == '__main__':

    name_outside = '5o.png'
    name_inside = '5i.png'
        
    inside = cv.imread(f'example\\{name_inside}')
    outside = cv.imread(f'example\\{name_outside}')

    inside_img = inside
    outside_img = outside

    inside = cv.cvtColor(inside, cv.COLOR_BGR2GRAY)
    outside = cv.cvtColor(outside, cv.COLOR_BGR2GRAY)

    left = 110; right = 255

    inside = cv.threshold(inside, left, right, cv.THRESH_BINARY)[1]
    outside = cv.threshold(outside, left, right, cv.THRESH_BINARY)[1]
    
    img = inside

    try:
        # print(len(inside.shape))
        if len(inside.shape) == 3:
            rows_inside, cols_inside, channels_inside = inside.shape
            rows_outside, cols_outside, channels_outside = outside.shape
        elif len(inside.shape) == 2:
            rows_inside, cols_inside = inside.shape
            rows_outside, cols_outside = outside.shape
    except Exception as e:
        print('Нет такого файла')
        sys.exit()

    xstart = rows_outside//2-rows_inside//2
    ystart = cols_outside//2-cols_inside//2

    roi = outside[xstart:xstart+rows_inside, ystart:ystart+cols_inside]
    roi_img = outside_img[xstart:xstart+rows_inside, ystart:ystart+cols_inside]
    tmp = roi.copy()
    insert_outside = roi_img.copy()

    # outside_img = rotate(outside_img, 45)
    mass = [0, 45, 90, 135, 180, 225, 270, 315]
    resultArray = []
    print('Программа запущенна...')
    with ThreadPoolExecutor(max_workers=8) as executor:
        for i, item in enumerate(mass):
            resultArray.append(executor.submit(rotate_and_check, inside.copy(), outside.copy(), item).result())

    resultArray.sort(key=lambda x: x[1])
    result1 = resultArray[0][0]
    result2 = resultArray[1][0]

    print(f'Первый угол: {result1}, {result1-360}')
    print(f'Второй угол: {result2}, {result2-360}')

    show_result(insert_outside, inside_img, outside_img, result1)
    show_result(insert_outside, inside_img, outside_img, result2)
cv.waitKey(0)
cv.destroyAllWindows()
