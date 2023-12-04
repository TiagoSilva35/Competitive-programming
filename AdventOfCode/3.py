import sys
matrix = []
for line in sys.stdin:
    cline = line.strip()
    matrix.append(cline)

found = False
temp = 0
ans = 0

def valid(i,j):
    if i < len(matrix)  and j < len(matrix[0]) and matrix[i][j] != '.' and matrix[i][j].isdigit() == False:
        return True

di = [-1, 1, 0, 0, -1, -1, 1, 1]
dj = [0, 0, -1, 1, -1, 1, -1, 1]


for row in range(len(matrix)):
    for col in range(len(matrix[row])):
        if matrix[row][col].isdigit():
            temp *= 10 
            temp += int(matrix[row][col])
            for i in range(len(di)):
                if (valid(row + di[i], col + dj[i])):
                    found = True
        
        else:
            if found:
                ans += temp
                temp = 0
                found = False
            else:
                temp = 0

print(ans)