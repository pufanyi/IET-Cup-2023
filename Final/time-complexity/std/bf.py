if __name__ == "__main__":
    MOD = 1000000000
    n = int(input())
    fac = 1
    for i in range(1, n + 1):
        fac = fac * i % MOD
    print(fac)
