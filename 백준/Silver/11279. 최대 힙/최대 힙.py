import heapq, sys

N = int(sys.stdin.readline())

arr = []
for _ in range(N):
    x = int(sys.stdin.readline())
    if x!=0 :
        heapq.heappush(arr, -x)
    else:
        if arr :
            print(-heapq.heappop(arr))
        else :
            print(0)


