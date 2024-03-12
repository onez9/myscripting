from PIL import Image

img = Image.open(r'''gradient.jpg''')

width, height = img.size

kx = 256 / width
ky = 256 / height

for y in range(height):
    for x in range(width):
        r, g, b = img.getpixel((x,y))
        clr = int((kx * y)/2)
        r, g, b = clr, clr, clr
        img.putpixel((x, y), (r, g, b))

img.show()
