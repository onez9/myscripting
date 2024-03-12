from math import sqrt,sin,pi
from numpy import empty
from pylab import imshow,gray,show

wavelength = 10
k = 2*pi/wavelength # Волновое число связано с длиной волной соотношением
xi0 = 1.0
separation = 20.0      # Separation of centers in cm
side = 200.0           # Side of the square in cm
points = 500           # Number of grid points along each side
spacing = side/points  # Spacing of points in cm

# wavelength = 150E-9 # 550 нм (550 * 10**-9 м)
# k = 2*pi/wavelength
# xi0 = 1.0
# separation = wavelength*4  # между источниками 4 длины волны (0.0022 мм)
# side = 1E-5  # Сторона рисунка - 0.01 мм
# points = 500
# spacing = side/points

# Calculate the positions of the centers of the circles
x1 = side/2 + separation/2
y1 = side/2
x2 = side/2 - separation/2
y2 = side/2

# Make an array to store the heights
xi = empty([points, points], float)

# Calculate the values in the array

for i in range(points):
    y = spacing*i
    for j in range(points):
        x = spacing*j
        #print(f"(x, y): {x, y} spacing * i = {spacing} * {i} = {spacing*i}")
        r1 = sqrt((x-x1)**2+(y-y1)**2)
        r2 = sqrt((x-x2)**2+(y-y2)**2)
        #xi[i,j] = xi0*sin(k*r1) + xi0*sin(k*r2)
        #print("not found")
        #if r1 > 3 and r1 < 6:
            #print(f"(x, y): {x, y} spacing * i = {spacing} * {i} = {spacing*i}")
        xi[i,j] = sin(k*r1) + sin(k*r2) 

# Make the plot
#imshow(xi,origin="lower",extent=[0,side,0,side])
imshow(xi)
#gray()
show()