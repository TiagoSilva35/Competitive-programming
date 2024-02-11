n = int(input())
arr = list(map(int, input().split()))
total = sum(arr)
sorted(arr)
ans = 0;

def solution(arr, idx, cur_sum):
    if (idx == len(arr)):
        return abs((total-cur_sum) - cur_sum)
    return min(solution(arr, idx + 1, cur_sum + arr[idx]), solution(arr, idx + 1, cur_sum))

print(solution(arr, 0, 0))


        
