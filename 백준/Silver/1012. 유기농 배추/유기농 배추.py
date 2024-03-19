from collections import deque

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

T = int(input())
for _ in range(T):
    M, N, K = map(int, input().split())

    bd = [[0]*51 for _ in range(51)]
    vis = [[0]*51 for _ in range(51)]

    for _ in range(K):
        x, y = map(int, input().split())
        bd[y][x] = 1
    
    ans = 0
    for i in range(N):
        for j in range(M):
            if bd[i][j] == 1 and vis[i][j] == 0:
                ans += 1
                q = deque([[i,j]])
                vis[i][j] = 1

                while q :
                    cy, cx = q.popleft()

                    for k in range(4):
                        ny = cy + dy[k]
                        nx = cx + dx[k]

                        if ny < 0 or nx < 0 or ny >= N or nx >= M :
                            continue
                        if vis[ny][nx] == 1 or bd[ny][nx] == 0 :
                            continue

                        q.append([ny,nx])
                        vis[ny][nx]=1
    
    print(ans)