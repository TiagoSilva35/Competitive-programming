def gray_code(n):
    """Generate a list of n-bit Gray codes."""
    if n == 0:
        return ["0"]
    if n == 1:
        return ["0", "1"]

    prev_list = gray_code(n - 1)

    result = ["0" + code for code in prev_list]

    result.extend(["1" + code for code in reversed(prev_list)])

    return result

n = int(input())
o = gray_code(n)
for i in o:
    print(i)