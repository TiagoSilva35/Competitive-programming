matrix = []
vis_rows = [False for i in range(9)]
ans = 0
for i in range(8):
    line = str(input())
    matrix.append(line)

Q = [0] * 9

def attack(col, row):
    for i in range(1, col):
        if Q[i] == Q[col] or abs(Q[i] - Q[col]) == abs(i - col):
            return False
    return True

def ways(col):
    global ans
    if (col == 9):
        ans += 1
    for i in range(1, 9):
        if (vis_rows[i] == False):
            if (matrix[i - 1][col - 1] == '*'):
                continue;
            vis_rows[i] = True;
            Q[col] = i;
            if attack(col, i):
                ways(col + 1) 
            vis_rows[i] = False;

ways(1)
print(ans)
