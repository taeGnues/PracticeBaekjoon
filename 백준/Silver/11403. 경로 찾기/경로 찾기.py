from collections import deque

N = int(input())

bd = {}

for i in range(N):
    bd[i] = []
    t = list(map(int, input().split()))
    for j in range(len(t)):
        if t[j] == 1:
            bd[i].append(j)

def bfs(st, ed): # 가중치 없는 그래프의 최단 거리는 BFS.
    q = deque()
    vis = {}
    q.append(st)
    vis[st] = True
    
    while q:
        cur = q.popleft()
        for i in bd[cur]:
            if i == ed:
                return True
            
            if i in vis :
                continue

            q.append(i)
            vis[i] = True
            
    
    return False

for i in range(N):
    line = []
    for j in range(N):
        if bfs(i, j):
            line.append(1)
        else :
            line.append(0)

    print(' '.join(list(map(str, line))))

