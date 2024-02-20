import sys
from collections import deque
input=sys.stdin.readline

def solution(nums, total_size):
    ans = 0
    queue = deque([i+1 for i in range(total_size)])
    
    for i in nums:
        mid = len(queue) // 2
        while queue[0]!=i :
            if mid < queue.index(i) :
                queue.rotate(1)
                ans+=1
            elif mid >= queue.index(i) :
                queue.rotate(-1)
                ans+=1
        queue.popleft()
    
    return ans


total_size, n = map(int, input().split())
nums = list(map(int, input().split()))

print(solution(nums, total_size))