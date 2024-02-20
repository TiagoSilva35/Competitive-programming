from math import ceil, log

def getMid(s, e):
    return s + (e - s) // 2

def getPdtUtil(st, ss, se, qs, qe, si):
    if qs <= ss and qe >= se:
        return st[si]
    if se < qs or ss > qe:
        return 1
    mid = getMid(ss, se)
    return ((getPdtUtil(st, ss, mid, qs, qe, 2 * si + 1)%m) *
            (getPdtUtil(st, mid + 1, se, qs, qe, 2 * si + 2)%m))%m

def getPdt(st, n, qs, qe):
    if qs < 0 or qe > n - 1 or qs > qe:
        print("Invalid Input")
        return -1
    return getPdtUtil(st, 0, n - 1, qs, qe, 0)

def constructSTUtil(arr, ss, se, st, si):
    if ss == se:
        st[si] = arr[ss]
        return arr[ss]
    mid = getMid(ss, se)
    st[si] = (constructSTUtil(arr, ss, mid, st, si * 2 + 1) *
              constructSTUtil(arr, mid + 1, se, st, si * 2 + 2))
    return st[si]

def constructST(arr, n):
    x = ceil(log(n, 2))
    max_size = 2 * pow(2, x) - 1
    st = [0] * max_size
    constructSTUtil(arr, 0, n - 1, st, 0)
    return st

def solve():
    global n, m
    n, m = map(int, input().split())
    p = 1
    v = list(map(int, input().split()))
    for i in range(n):
        p *= v[i]
    s = input()
    ans = []
    st = constructST(v, n)
    lb, rb = 0, n - 1
    for i in range(n):
        p = getPdt(st, n, lb, rb)
        ans.append(p % m)
        if s[i] == 'R':
            p //= v[rb]
            rb -= 1
        if s[i] == 'L':
            p //= v[lb]
            lb += 1
    print(*ans)

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
