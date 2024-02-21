import sys
input=sys.stdin.readline


def solution(nums):
    mx = -1000000
    mn = 1000000

    for i in nums:
        if mx <= i : mx = i
        if mn >= i : mn = i
    
    return [mn, mx]


n = int(input())
nums = list(map(int, input().split()))
ans = solution(nums)
print(ans[0], ans[1])