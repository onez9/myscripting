# import cv2 as cv
# import pytesseract
# import matplotlib.pyplot as plt
# from PIL import Image


# image = cv.imread('test-text.jpg')
# str1 = pytesseract.image_to_string(image)
# print(str1)



def func(n):
    acc=0
    while acc<n:
        yield acc
        acc += 1
    yield 0

g=func(10)

print(g.__next__())
print(g.__next__())
print(next(g))
print(next(g))
print(next(g))
print(next(g))
print(next(g))
print(next(g))


