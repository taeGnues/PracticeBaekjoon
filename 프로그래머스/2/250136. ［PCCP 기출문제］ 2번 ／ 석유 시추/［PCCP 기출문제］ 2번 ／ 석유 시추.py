from collections import deque

def solution(land):
    M = len(land[0])
    N = len(land)
    res = [0 for _ in range(0,M)]
    answer = 0
    vis = {}
    for i in range(N): 
        for j in range(M): 
            if land[i][j] == 1 and (i, j) not in vis:
                min_y = j
                max_y = j
                petro = 0
                q = deque([(i,j)])
                vis[(i,j)] = True
                
                while q:
                    cx, cy = q.popleft()
                    petro += 1
                    min_y = min(min_y, cy)
                    max_y = max(max_y, cy)
                    
                    for d in [(0,1), (1,0), (-1,0), (0,-1)]:
                        nx = cx + d[0]
                        ny = cy + d[1]
                        
                        if nx < 0 or ny < 0 or nx >= N or ny >= M :
                            continue
                        if (nx, ny) in vis or land[nx][ny] == 0:
                            continue
                        
                        q.append((nx,ny))
                        vis[(nx,ny)] = True
                for k in range(min_y, max_y+1):
                    res[k] += petro
            

    return max(res)