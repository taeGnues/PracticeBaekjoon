import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())

bd = []
tx, ty = 0, 0
for i in range(N):
    tmp = list(map(int, sys.stdin.readline().split()))
    for j in range(M):
        if tmp[j]==2:
            tx, ty = i, j
    bd.append(tmp)

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]
vis = {(tx, ty):0}
q = deque([(tx, ty)])

while q :
    cx, cy = q.popleft()

    for d in range(4):
        nx = cx + dx[d]
        ny = cy + dy[d]

        if nx < 0 or ny < 0 or nx >= N or ny >= M:
            continue
        if bd[nx][ny]==0 or (nx, ny) in vis:
            continue
        
        q.append((nx, ny))
        vis[(nx, ny)] = vis[(cx, cy)] + 1

for i in range(N):
    for j in range(M):
        if bd[i][j] == 0 :
            print(0, end=' ')
        elif (i,j) in vis :
            print(vis[(i, j)], end=' ')
        else:
            print(-1, end=' ')
    print()