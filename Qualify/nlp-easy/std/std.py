def solve():
    s = input()
    T = "ietntu"
    now = 0
    for c in s:
        if c == T[now]:
            now += 1
            if now == 6:
                break
    if now == 6:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solve()
