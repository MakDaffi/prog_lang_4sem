import numpy as np
import matplotlib.pyplot as plt
import numexpr as ne

# Создание объекта поля, на котором будем отрисовывать наш график функции
plt.style.use('ggplot')
fig, ax = plt.subplots()

# Подписи на графике (название осей)
ax.set_xlabel('Axis x')
ax.set_ylabel('Axis y')


def start(a, b, x):
    for i in range(a * 100, b * 100):
        x.append(i * 0.01)
    # Установка пределов
    ax.set_xlim(a, b)


# sin x
def sin(a, b):
    # Отрисовка графика по заданным параметрам
    x = []
    start(a, b, x)
    ax.plot(x, np.sin(x))

    # Установление пределов
    ax.set_ylim(-2, 2)

    # Подписи на графике (название функции)
    ax.set_title('y = sin(x)', fontsize=30)

    plt.show()


# ax^2+bx+c
def par(v, v2, a, b, c):
    # Отрисовка графика по заданным параметрам
    y = []
    x = []
    start(v, v2, x)
    min = 1000000
    max = -1000000
    for i in range(len(x)):
        v = x[i] * x[i] * a + x[i] * b + c
        y.append(v)
        if v < min:
            min = v
        if v > max:
            max = v
    ax.plot(x, y)

    # Установление пределов
    ax.set_ylim(min, max)

    # Подписи на графике (название функции)
    ax.set_title('Parabola', fontsize=30)

    plt.show()


def lin(a, v, k, b):
    # Отрисовка графика по заданным параметрам
    y = []
    x = []
    start(a, v, x)
    min = 1000000
    max = -1000000
    for i in range(len(x)):
        v = x[i] * k + b
        y.append(v)
        if v < min:
            min = v
        if v > max:
            max = v
    ax.plot(x, y)

    # Установление пределов
    ax.set_ylim(min, max)

    # Подписи на графике (название функции)
    ax.set_title('y = kx + b', fontsize=30)

    plt.show()


def cos(a, b):
    # Отрисовка графика по заданным параметрам
    x = []
    start(a, b, x)
    ax.plot(x, np.cos(x))

    # Установление пределов
    ax.set_ylim(-2, 2)

    # Подписи на графике (название функции)
    ax.set_title('y = cos(x)', fontsize=30)

    plt.show()


def kyb(a, b):
    # Отрисовка графика по заданным параметрам
    y = []
    x = []
    start(a, b, x)
    min = 1000000
    max = -1000000
    for i in range(len(x)):
        v = x[i] ** 3
        y.append(v)
        if v < min:
            min = v
        if v > max:
            max = v
    ax.plot(x, y)
    plt.show()

    # Установление пределов
    ax.set_ylim(min, max)

    # Подписи на графике (название функции)
    ax.set_title('y = kx + b', fontsize=30)


def vvod(a, b, f):
    x = []
    start(a, b, x)
    min = 1000000
    max = -1000000
    nf = f if 'x' in f else 'x/x * ({})'.format(f)
    y = ne.evaluate(nf)
    for i in range(len(y)):
        if y[i] < min:
            min = y[i]
        if y[i] > max:
            max = y[i]
    ax.plot(x, y)
    plt.show()

    # Установление пределов
    if min != max:
      ax.set_ylim(min, max)
    else: ax.set_ylim(min - 2, max + 2)

    # Подписи на графике (название функции)
    ax.set_title(f, fontsize=30)


def file(a, b, f):
    ax.set_xlim(a, b)
    x = []
    y = []
    c = open(f, 'r')
    l = [line.strip() for line in c]
    min = 1000000
    max = -1000000
    for i in range(len(l)):
        z = int(l[i])
        if i % 2 == 0:
          x.append(z)
        else:
            y.append(z)
            if z < min:
                min = z
            if z > max:
                max = z
    ax.plot(x, y)

    # Установление пределов
    ax.set_ylim(min - 2, max + 2)
    plt.show()