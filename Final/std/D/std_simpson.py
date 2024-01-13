# Use the simpson method to calculate the integral of a function.


from typing import Callable


def simpson(f: Callable, l: float, r: float) -> float:
    return (f(l) + 4 * f((l + r) / 2) + f(r)) * (r - l) / 6


def integral(f: Callable, l: float, r: float, eps: float = 1e-10) -> float:
    m = (l + r) / 2
    ans = simpson(f, l, r)
    if abs(simpson(f, l, m) + simpson(f, m, r) - ans) < 15 * eps:
        return ans
    return integral(f, l, m, eps / 2) + integral(f, m, r, eps / 2)


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        l, r = map(int, input().split())
        print("%.6f" % integral(lambda x: 1 / (x * x + 1) ** 3, l, r))
