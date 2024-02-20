def sum_of_digits(n):
    return (n * (n + 1) // 2) % 9

def final_sum(t, test_cases):
    results = []
    for n in test_cases:
        results.append(sum_of_digits(n))
    return results

# Input reading
t = int(input())
test_cases = [int(input()) for _ in range(t)]

# Output
results = final_sum(t, test_cases)
for result in results:
    print(result)
