import heapq

N = int(input())

min_heap = []

for _ in range(N):
    st, ed = map(int, input().split())
    heapq.heappush(min_heap, (ed, st))

    # 1. 가장 빨리 끝나는 것만 선택
    # 2. 만약 끝나는 시간이 같다면, 더 늦게 시작하는 것만 선택
cur_ed, cur_st = heapq.heappop(min_heap)
ans = 1
while min_heap:
    nxt_ed, nxt_st = heapq.heappop(min_heap)
    if nxt_st < cur_ed :
        continue
    
    cur_ed = nxt_ed
    cur_st = nxt_st
    ans+=1

print(ans)
    
