n = int(input())
l = list(map(int, input().split()))

ans = n
aux = []
i = 0
temp = 1
flag = False
while len(aux) != n:
    if (i == n): Flag = True
    if (i < n):
        if (l[i] == temp):
            temp+=1
            i+=1
            aux.append(temp)
            flag = False
    
    else:
        i = i - 1 if flag else i + 1 
    
print(len(aux))
