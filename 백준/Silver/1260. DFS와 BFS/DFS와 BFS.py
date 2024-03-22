from collections import deque

N, M, V = map(int, input().split())

adj = [[] for _ in range(N+1)] # 0번부터 N번까지.

for i in range(M):
    e1, e2 = map(int, input().split())
    adj[e1].append(e2)
    adj[e2].append(e1)

for i in range(1,N+1): # 모두 1..N으로 정렬해주기
    adj[i].sort()

vis2 = []
def dfs(cur_v):
    vis2.append(cur_v)

    for i in adj[cur_v]:
        if i not in vis2:
            dfs(i)
    return

def bfs():
    ans = [V]
    vis = {V: True}
    q = deque([V])

    while q :
        cur = q.popleft()
        for i in adj[cur]:
            if i in vis:
                continue
            
            ans.append(i)
            q.append(i)
            vis[i] = True
    
    print(' '.join(map(str, ans)))

dfs(V)
print(' '.join(map(str, vis2)))
bfs()