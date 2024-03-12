import pygame
import random
pygame.init()

############################################################
FPS = 60
width = 500
height = 500
size = (width, height)
xCord = 250
yCord = 250
radius = 20
DRxCord = 1
DRyCord = 1
direct = DRxCord # 1 - Вправо | -1 - Влево
cours = DRyCord # 1 - Вниз | -1 - Вверх
clock = pygame.time.Clock()
jumpCount = 10
isJump = False
#############################################################
pygame.display.set_caption("My first game")
surface = pygame.display.set_mode(size)
surface.fill((255, 255, 255))

pygame.display.update()

while True:

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()

#############################################################

    keys = pygame.key.get_pressed()

    if keys[pygame.K_a]:
        xCord -= 3
    if keys[pygame.K_d]:
        xCord += 3
    if not(isJump): 
        if keys[pygame.K_UP]:
            y -= 3
        if keys[pygame.K_DOWN]:
            yCord += 3
        if keys[pygame.K_SPACE]:
            isJump = True
    else:
        if jumpCount >= -10:
            yCord -= (jumpCount * abs(jumpCount)) * 0.5
            jumpCount -= 1
        else: 
            jumpCount = 10
            isJump = False


##############################################################

    surface.fill((255, 255, 255))
    pygame.draw.line(surface, (0, 255, 0), (0, 250), (500, 250), 5)
    pygame.draw.circle(surface, (255, 0, 0), (xCord, yCord), radius)
    pygame.display.update()

    clock.tick(FPS)