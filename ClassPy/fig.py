import pygame


class Figure(pygame.sprite.Sprite):
    def __init__(self, a=0, b=0, d=(0, 0, 255)):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.Surface((a, b))
        self.image.fill(d)
        self.rect = self.image.get_rect()
        self.rect.center = (WIDTH / 2, HEIGHT / 2)

    def draw_area(self, s, p):
        font = pygame.font.SysFont('courier', 25)
        screen.blit(font.render(s, True, WHITE), [2, 50])
        screen.blit(font.render(p, True, WHITE), [2, 75])

    def area(self):
        raise NotImplementedError()


class Point(Figure):
    def __init__(self, a=1, b=1):
        Figure.__init__(self, a, b)

    def area(self):
        self.draw_area('S = 0', 'P = 0')


class Polygon(Figure):
    def __init__(self, a, b, c, d=(255, 0, 0)):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.Surface((a, b))
        self.image.fill(BLACK)
        self.rect = self.image.get_rect()
        self.rect.center = (WIDTH / 2, HEIGHT / 2)
        pygame.draw.polygon(self.image, d, c, 0)


class Triangle(Polygon):
    def __init__(self, a=200, b=200, c=None):
        if c is None:
            c = [[100, 25], [0, 200], [200, 200]]
        Polygon.__init__(self, a, b, c, (0, 255, 0))

    def area(self):
        self.draw_area('S = 1/2 * a * h', 'P = a + b + c')


class Square(Polygon):
    def __init__(self, a=200, b=200, c=None):
        if c is None:
            c = [[0, 0], [0, 200], [200, 200], [200, 0]]
        Polygon.__init__(self, a, b, c)

    def area(self):
        self.draw_area('S = a^2', 'P = 4 * a')


class Circle(Figure):
    def __init__(self, a=200, b=200, d=(255, 0, 102)):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.Surface((a, b))
        self.image.fill(BLACK)
        self.rect = self.image.get_rect()
        self.rect.center = (WIDTH / 2, HEIGHT / 2)
        pygame.draw.circle(self.image, d, (a/2, b/2), 100, 0)

    def area(self):
        self.draw_area('S = Pi * R^2', 'P = 2 * Pi * R')


# Цвета (R, G, B)
PINK = (255, 0, 102)
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
WIDTH = 360  # ширина игрового окна
HEIGHT = 480 # высота игрового окна
FPS = 60 # частота кадров в секунду


# создаем игру и окно
k = 0
pygame.init()
pygame.mixer.init()  # для звука
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("My Game")
clock = pygame.time.Clock()



# Цикл игры
running = True
while running:
    # Держим цикл на правильной скорости
    clock.tick(FPS)
    # Ввод процесса (события)
    for event in pygame.event.get():
        # check for closing window
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_2 and k < 3:
                k += 1
            elif event.key == pygame.K_1 and k > 0:
                k -= 1
    all_sprites = pygame.sprite.Group()

    if k == 0:
        fig = Point()
    elif k == 1:
        fig = Square()
    elif k == 2:
        fig = Circle()
    elif k == 3:
        fig = Triangle()
    all_sprites.add(fig)

    # Обновление
    all_sprites.update()
    # Рендеринг
    screen.fill(BLACK)
    all_sprites.draw(screen)

    fig.area()

    # После отрисовки всего, переворачиваем экран
    pygame.display.flip()

pygame.quit()