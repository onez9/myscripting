from PIL import Image


# size of pic
def get_image_resize(img, height_new):
    width, height = img.size
    width_new = width // (height//height_new)
    img_new = img.resize((width_new, height_new), Image.ANTIALIAS)
    return img_new


# pic symbols
def get_image_symbols(img_new):
    width, height = img_new.size
    segment = 256 * 256 * 256 // len(symbols)
    result = ''
    for y in range(height):
        for x in range(width):
            r, g, b = img_new.getpixel((x, y))
            # color = r * g * b
            if switching_ch == 1:
                color = abs(255 - r) * abs(255 - g) * abs(255 - b)
            elif switching_ch == 2:
                color = r * g * b
            pos = color // segment
            result += symbols[pos] * 2
        result += '\n'
    pic.append(result)
    return result

    
print("Hello ", "my friends")


# inverting sides
def inverting_pic_sides(result):
    with open(f'output_ascii.txt', mode='w', encoding='utf8') as out:
        if inverting_ch == 1:
            for i in range(len(pic)):
                out.write(pic[i])

        if inverting_ch == 2:
            for i in range(len(pic)-1, 0, -1):
                out.write(pic[i])

        if inverting_ch == 3:
            for i in range(len(pic)):
                for k in range(len(pic)-1, 0, -1):
                    out.write(pic[i][k])

        if inverting_ch == 4:
            for i in range(len(pic)-1, 0, 1):
                for k in range(len(pic)-1, 0, -1):
                    out.write(pic[i][k])



print('Отражение?')
while True:
    inverting_ch = int(input('1 - Нет\n'
                             '2 - Перевернуть\n'
                             '3 - Отзеркаливание\n'
                             '4 - Всё\n'))
    break
print('Инвертация цвета?')
while True:
    switching_ch = int(input('1 - Да\n'
                             '2 - Нет\n'))
    break


img = Image.open('ascii.jpg')
img_new = get_image_resize(img, 50)
pic = []
symbols = '.:;+*123#░ &?#░▒▓█'
result = get_image_symbols(img_new)
inverting_pic_sides(result)

