# 1~6, 10*10 (1..100)
# 주사위 굴려나온

import sys
from collections import deque
sys.setrecursionlimit(10**8)

N, M = map(int, sys.stdin.readline().split())

snakes_and_ladders = {} # 뱀과 사다리 정보 저장

for _ in range(N):
    x, y = map(int, sys.stdin.readline().split())
    snakes_and_ladders[x] = y

for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    snakes_and_ladders[u] = v

q = deque([1])
vis = {1:0}

while q: # BFS
    curr = q.popleft()

    if curr == 100:
        print(vis[curr])
        break

    for dice in range(1, 7):
        nxt = curr + dice
        
        if nxt in vis:
            continue

        if nxt in snakes_and_ladders:
            nxt = snakes_and_ladders[nxt]

        if nxt in vis: # snake 때문에 한번더 체크해주기
            continue

        vis[nxt] = vis[curr]+1
        q.append(nxt)
    