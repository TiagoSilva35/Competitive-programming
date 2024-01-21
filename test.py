inpu = input().split()
n, h = int(inpu[0]), int(inpu[1])
l = []
idx = 0
f = []
for i in range(h):
    temp = str(input()).strip("  ").split("|")
    good = []
    for i in temp:
        if i != '' and i != "   ":
            good.append(i[1])
        else:
            good.append(" ")

    k = 0
    l.append(good)
    for i in l[idx]:
        f.append([i]) if k >= len(f) else f[k].append(i)
        k+=1
    temp.clear
    idx += 1
    good.clear
f = f[1:n + 1]
q = int(input())
for i in range(q):
    sinp = input().split()
    f[int(sinp[2]) - 1].append(f[int(sinp[1]) - 1][0])
    del(f[int(sinp[1]) - 1][0])
ans = ""
for i in f:
    flag = False
    cur = 0
    for j in i:
        if j != ' ':
            cur = j
            if len(i) == h:
                ans += cur
                flag = True
                break
    if (cur != 0):
        if (not flag):
            ans += cur
print(ans)
    