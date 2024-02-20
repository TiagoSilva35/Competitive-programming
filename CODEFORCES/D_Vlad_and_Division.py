def min_groups(t, test_cases):
    results = []
    
    for test in test_cases:
        n, numbers = test
        unique_patterns = set()

        for num in numbers:
            binary_pattern = format(num, '031b')
            unique_patterns.add(binary_pattern)

        groups_needed = len(unique_patterns)
        results.append(groups_needed)

    return results

# Input parsing
t = int(input())
test_cases = []

for _ in range(t):
    n = int(input())
    numbers = list(map(int, input().split()))
    test_cases.append((n, numbers))

# Get the results
output = min_groups(t, test_cases)

# Output the results
for result in output:
    print(result)
