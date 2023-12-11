def f(x):
    return 1 / (x * x + 1) ** 3


def integral(l, r):
    step = 1e-5
    ans = 0
    while l < r:
        ans += f(l) * step
        l += step
    return ans


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        l, r = map(int, input().split())
        l = max(-10, l)
        r = min(10, r)
        print(integral(l, r))
