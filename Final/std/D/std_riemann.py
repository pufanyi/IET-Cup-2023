# Take integral as the Riemann sum of a function.


def f(x):
    return 1 / (x * x + 1) ** 3


def integral(l, r):
    step = 1e-4
    ans = 0
    while l < r:
        ans += f(l) * step
        l += step
    return ans


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        l, r = map(int, input().split())
        # To make it faster, we can limit the range of the integral.
        # Because out of the range [-10, 10], the value of the function is very small.
        l = max(-10, l)
        r = min(10, r)
        print(integral(l, r))
