import imquality.brisque as brisque
import PIL.Image

path = 'test5.jpg'
img = PIL.Image.open(path)
brisque.score(img)


