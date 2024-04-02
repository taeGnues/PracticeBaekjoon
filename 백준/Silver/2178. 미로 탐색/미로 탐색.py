from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

N, M = map(int, input().split())
bd = [[0]*M for _ in range(N)]
vis = [[0]*M for _ in range(N)]

for i in range(N):
    t = input()
    for j in range(M):
        bd[i][j] = int(t[j])

q = deque()
q.append((0, 0))
vis[0][0] = 1

while q :
    cx, cy = q.popleft()
    

    for i in range(4):
        nx = cx + dx[i]
        ny = cy + dy[i]

        if nx < 0 or ny < 0 or nx >= N or ny >= M:
            continue
        if vis[nx][ny]!=0 or bd[nx][ny]==0 :
            continue

        q.append((nx,ny))
        vis[nx][ny] = vis[cx][cy] + 1

print(vis[N-1][M-1])

