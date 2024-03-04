t = int(input())

for _ in range(t):
    n = int(input())
    total_sum = 0
    while n > 0:
        total_sum += n % 10
        n //= 10
    print(total_sum)