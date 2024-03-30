import heapq, sys

N = int(sys.stdin.readline())
min_heap = []
heapq.heapify(min_heap)


for i in range(N):
    n = int(sys.stdin.readline())
    if n == 0 :
        if min_heap :
            print(heapq.heappop(min_heap))
        else :
            print(0)
    else:
        heapq.heappush(min_heap, n)