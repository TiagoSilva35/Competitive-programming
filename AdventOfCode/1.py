ans = 0
strings = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
nums = {"one" : '1', "two": '2',"three": '3',"four": '4',"five": '5',"six": '6',"seven": '7',"eight": '8',"nine": '9'}
while True:
    s = str(input())
    l = []
    for i in range(len(s)):        
        for j in range(0, i):
            if s[j:i+1] in strings:
                l.append(nums[s[j:i+1]]) 
        if s[i].isnumeric():
            l.append(s[i])

    if s == '':
        print(ans)
        break
    else: 
        ans += ((ord(l[0]) - ord('0')) * 10 + (ord(l[-1]) - ord('0')))        
    