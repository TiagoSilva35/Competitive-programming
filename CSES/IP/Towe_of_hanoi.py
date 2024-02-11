n = int(input())

def toh(a, b, c, n):
    if (n == 0):
        return
    toh(a, c, b, n-1)
    print(f"{a} {c}")
    toh(b, a, c, n-1)

print ((1 << n) - 1)
toh(1, 2, 3, n)
