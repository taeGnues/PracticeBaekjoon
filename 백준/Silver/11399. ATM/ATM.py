import heapq

N = int(input())

arr = list(map(int, input().split()))

heapq.heapify(arr)

ans = 0
tmp = 0 
while arr:
    cur = heapq.heappop(arr)
    tmp+=cur
    ans+=tmp

print(ans)