from collections import deque


dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

N = int(input())

bd = [list(map(int, list(input().strip()))) for _ in range(N)]


vis = {}
answer = []

def bfs(x, y):
    q = deque()
    q.append((x,y))
    vis[(x,y)] = True
    cnt = 1
    while q:
        cx, cy = q.popleft()  
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if nx < 0 or ny < 0 or nx >= N or ny >= N:
                continue
            if (nx, ny) in vis or bd[nx][ny]==0:
                continue

            q.append((nx,ny))
            vis[(nx,ny)] = True
            cnt+=1
    
    return cnt



for i in range(N):
    for j in range(N):
        if bd[i][j] == 1 and (i,j) not in vis:
            answer.append(bfs(i,j))


print(len(answer))
for i in sorted(answer):
    print(i)