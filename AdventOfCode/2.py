# 12 red cubes, 13 green cubes, and 14 blue cubes
ans = 0
while True:
    red = []
    blue = []
    green = []
    s = str(input()).strip()
    if s == '':
        print(ans)
        break
    l = s.split(":")
    idx = l[0].split(" ")[1]
    for i in l[1].split(";"):
        dic = {}
        for j in i.strip().split(","):
            temp = j.strip().split(" ")
            dic[temp[1].strip()] = 0 if temp[1].strip() not in dic.keys() else dic[temp[1].strip()]
            dic[temp[1].strip()] += int(temp[0].strip())
            if (temp[1].strip() == "red"): red.append(dic[temp[1].strip()])
            if (temp[1].strip() == "blue"): blue.append(dic[temp[1].strip()])
            if (temp[1].strip() == "green"): green.append(dic[temp[1].strip()])
    ans += (max(red)*max(blue)*max(green))


