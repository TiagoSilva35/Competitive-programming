import sys
matrix = []
for line in sys.stdin:
    cline = line.strip()
    matrix.append(cline)

ans = 0
lista = []
dic = {}
idx = -1
for i in matrix:
    idx += 1
    score = 0
    temp = (i.split(":"))[1].strip()
    win = ((temp.split("|"))[0].strip()).split(" ")
    m = ((temp.split("|")))[1].strip().split(" ")
    win = [i for i in win]
    m = [i for i in m]
    for i in win:
        if i == ' ' or i == '': 
            win.remove(i)
    for i in m:
        if i == ' ' or i == '': 
            m.remove(i)
    score = 0
    for ele in win:
        for o in m:
            if int(ele) == int(o):
                score += 1
    dic[idx + 1] = score
    lista.append(idx + 1)
    ans += 1

novaLista = lista

while(len(novaLista) > 0):
    for i in novaLista:
        novaLista.remove(i)
        for j in range(dic[i]):
            if i + j + 1 <= idx + 1:
                ans += 1
                novaLista.append(i + j + 1)


print(ans)