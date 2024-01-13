# Directly use the formula to calculate the integral.


import math


def f(x):
    return 3 / 8 * math.atan(x) + (3 * x ** 3 + 5 * x) / (8 * (x ** 2 + 1) ** 2)


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        l, r = map(int, input().split())
        print("%.12f" % (f(r) - f(l)))
