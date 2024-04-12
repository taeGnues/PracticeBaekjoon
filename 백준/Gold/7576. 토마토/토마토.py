from collections import deque

M, N = map(int, input().split())

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

bd = [list(map(int, input().split())) for _ in range(N)]

def check(): # 현재 토마토들이 모두 익었는지 확인함.
    for i in range(N):
        for j in range(M):
            if bd[i][j] == 0:
                return True 
    return False

vis = {}
q = deque() 

# 큐에 추가 & vis 설정
for i in range(N):
    for j in range(M):
        if bd[i][j]==1 and (i, j) not in vis:
            q.append((i,j))
            vis[(i, j)] = 0

while q:
    cx, cy = q.popleft()
    for i in range(4):
        nx = cx + dx[i]
        ny = cy + dy[i]

        if nx < 0 or ny < 0 or nx >= N or ny >= M :
            continue
        if bd[nx][ny]==-1 or (nx,ny) in vis:
            continue

        vis[(nx, ny)] = vis[(cx, cy)] + 1
        q.append((nx,ny))
        bd[nx][ny]=1

if check():
    print(-1)
    exit(0)

day = 0
for i in range(N):
    for j in range(M):
        if (i, j) in vis:
            day = max(day, vis[(i, j)])

print(day)




