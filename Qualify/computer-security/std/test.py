def check_prime(n):
    if n == 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
        if i * i > n:
            break
    return True

def check_hf(n):
    hf = [0, 2, 4, 5, 6, 8]
    for x in hf:
        if str(x) in str(n):
            return False
    return True

if __name__ == "__main__":
    num = 0
    num_prime = 0
    numm = [0] * 10
    for i in range(1000, 10000):
        if check_prime(i) and check_hf(i):
            # print(i)
            num += 1
            numm[i % 10] += 1
    sum = 0
    for x in numm:
        sum += x * x
    print(numm)
    print(sum)
    nump = [0] * 10
    nummm = [0] * 100
    ___ = [0] * 10
    for i in range(1000, 10000):
        if check_prime(i):
            num_prime += 1
            nump[i % 10] += 1
            nummm[int(str(i)[1:3])] += 1
            ___[int(str(i)[0])] += 1
    print(nummm)
    print(max(nummm) ** 4 * 9 ** 4)
    print("___", ___)
    sum *= 270
    sum *= max(nummm) ** 3
    print(max(nummm))
    print("sum =", sum)
    print(nump)
    print(num, num_prime)
    print(num_prime ** 3 * num)
    print(num * num * 9 ** 9)
    print(num ** 2 * num_prime * 9 ** 6)
