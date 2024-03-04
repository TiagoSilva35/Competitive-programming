def solve():
    S = input().strip()
    M = ord(input().strip()) - ord('A')
    n = len(S)
    dp = [[[[0]*3 for _ in range(3)] for _ in range(3)] for _ in range(n+1)]
    dp[n][0][0][0] = 1
    for i in range(n-1, -1, -1):
        for a in range(3):
            for b in range(3):
                for c in range(3):
                    if a == b and b == c:
                        continue
                    for d in range(3):
                        if d == a and d == b:
                            continue
                        dp[i][b][c][d] += dp[i+1][c][d][ord(S[i])-ord('A')] / 2
                        if d != c:
                            dp[i][b][c][d] += dp[i+1][c][d][3-a-b-c] / 2
    print("%.16f" % sum(dp[0][j][k][M] for j in range(3) for k in range(3)))

solve()