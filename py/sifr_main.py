from PIL import Image
from functions_for_sifr import get_alph, get_bit, get_text


def cifr_in_pic(alph, name_image, text):
    img = Image.open(name_image)
    width, height = img.size
    rastr = img.load()
    x, y = 0, 0
    i = 0
    while i < len(text):
        smb = text[i]
        pos = alph.find(smb)
        for shift in range(8):
            (r, g, b) = rastr[x, y]
            r = (b & 254) | get_bit(pos, shift)
            g = (b & 254) | get_bit(pos, shift)
            b = (b & 254) | get_bit(pos, shift)
            rastr[x, y] = (r, g, b)
            x += 1
            if x == width:
                x = 0
                y += 1
        i += 1
    img.save('1_' + name_image)
    img.show()


alph = get_alph()
text = get_text('input.txt')
name_image = 'sifr.jpg'

cifr_in_pic(alph, name_image, text)
