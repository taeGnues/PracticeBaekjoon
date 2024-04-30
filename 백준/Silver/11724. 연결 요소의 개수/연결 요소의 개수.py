import sys
sys.setrecursionlimit(10**5)
N, M = map(int, sys.stdin.readline().split())

adj = {
    i : [] for i in range(1, N+1)
}

for _ in range(M):
    a, b = map(int, sys.stdin.readline().split())
    adj[a].append(b)
    adj[b].append(a)

vis = {}
ans = 0
def go(curr):
        if not adj[curr]:
            return
        
        for j in adj[curr]:
            if j not in vis:
                vis[j] = True
                go(j)

for i in range(1, N+1):
    if i not in vis :
        ans += 1
        go(i)

print(ans)