import sys
matrix = []
for line in sys.stdin:
    cline = line.strip()
    matrix.append(cline)

found = False
tmp_idx = []
temp = 0
ans = 0

dic = {}

def valid(i,j):
    if i < len(matrix)  and j < len(matrix[0]) and matrix[i][j] == '*':
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
                    if [row + di[i], col +dj[i]] not in tmp_idx:
                        tmp_idx.append([row + di[i], col + dj[i]])
                    dic.setdefault(row + di[i],{})
                    dic[row + di[i]].setdefault(col + dj[i], [])
                    found = True


        else:
            if found:
                for i in tmp_idx:
                    dic[i[0]][i[1]].append(temp)
                found = False
            temp = 0
            tmp_idx = []

#print(dic)

for key in dic.keys():
    for key2 in dic[key].keys():
        if len(dic[key][key2]) == 2:
            ans += dic[key][key2][0]*dic[key][key2][1]

print(ans)