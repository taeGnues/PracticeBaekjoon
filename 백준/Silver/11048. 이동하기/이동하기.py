import sys
sys.setrecursionlimit(10**5)

N, M = map(int, sys.stdin.readline().split())
bd = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]


dp = {}
def go(sx, sy):
    if sx==N-1 and sy==M-1:
        return bd[sx][sy]
    
    if (sx, sy) in dp:
        return dp[(sx, sy)]

    dp[(sx, sy)] = 0
    for d in [(0,1), (1,0), (1,1)]:
        nx = sx + d[0]
        ny = sy + d[1]

        if nx < 0 or ny < 0 or nx >= N or ny >= M:
            continue
        
        dp[(sx, sy)] = max(dp[(sx, sy)], go(nx, ny) + bd[sx][sy])
        

    return dp[(sx, sy)]

print(go(0, 0))