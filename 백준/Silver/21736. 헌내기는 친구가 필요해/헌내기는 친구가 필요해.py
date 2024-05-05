from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
sx, sy = 0, 0


N, M = map(int, input().split())
bd = [[0]*M for _ in range(N)]
for i in range(N):
    s  = input()
    for j in range(M):
        bd[i][j] = s[j]
        if s[j] == 'I':
            sx = i
            sy = j
ans = 0

q = deque()
vis = {}
q.append((sx, sy))
vis[(sx, sy)] = True

while q:
    cx, cy = q.popleft()

    for i in range(4):
        nx = cx + dx[i]
        ny = cy + dy[i]

        if nx < 0 or ny < 0 or nx >= N or ny >= M:
            continue
        if (nx, ny) in vis or bd[nx][ny] == 'X':
            continue
        if bd[nx][ny] == 'P':
            ans+=1
        
        q.append((nx, ny))
        vis[(nx,ny)]=True

print(ans if ans!=0 else 'TT')