def gcd(a: int, b: int) -> int:
    while b != 0:
        a, b = b, a % b
    return a


def solve():
    n, k = map(int, input().split())
    ans = 0
    for x in map(int, input().split()):
        if x % k == 0:
            ans = gcd(ans, x)
    if ans == k:
        print("YES")
    else:
        print("NO")


T = int(input())
for _ in range(T):
    solve()
