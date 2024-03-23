from collections import deque

N, M = map(int, input().split())

adj = {i:[] for i in range(1,N+1)}

for _ in range(M):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)


def bfs(cur_v):
    vis = {}
    q = deque([cur_v])
    vis[cur_v] = 0

    while q :
        cur = q.popleft()
        for i in adj[cur]:
            if i in vis :
                continue
            q.append(i)
            vis[i] = vis[cur]+1
    
    return sum(vis.values())

ans = 1
min_value = bfs(1)
for i in range(2, N+1):
    kevin_num = bfs(i)
    if min_value > kevin_num:
        ans = i
        min_value = kevin_num


print(ans)