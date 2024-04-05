from collections import deque

N = int(input())
bd = []
zero_cnt=0
one_cnt=0

dx = [1,-1,0,0]
dy = [0,0,1,-1]

for i in range(N):
    bd.append(list(map(int, input().split())))



def bfs(sx, sy, bdsize):
    q = deque()
    vis = {(sx,sy):True}
    q.append((sx,sy))

    value = bd[sx][sy]

    while q:
        cx, cy = q.popleft()

        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if nx < sx or ny < sy or nx >= sx+bdsize or ny >= sy+bdsize:
                continue
            if (nx, ny) in vis:
                continue
            if bd[nx][ny] != value: # 0 혹은 1이 아니면.
                return False
            
            vis[(nx,ny)] = True
            q.append((nx,ny))
    
    return True

def go(sx, sy, bdsize):

    global one_cnt, zero_cnt
    
    if bdsize == 1:
        if bd[sx][sy]==1:
            one_cnt+=1
        else:
            zero_cnt+=1
        return
    
    if bfs(sx, sy, bdsize):
        if bd[sx][sy]==1:
            one_cnt+=1
        else:
            zero_cnt+=1
        return

    go(sx, sy, bdsize//2)
    go(sx, sy+bdsize//2, bdsize//2)
    go(sx+bdsize//2, sy, bdsize//2)
    go(sx+bdsize//2, sy+bdsize//2, bdsize//2)

    return

go(0, 0, N)

print(zero_cnt)
print(one_cnt)
