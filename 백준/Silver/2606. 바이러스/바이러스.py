N = int(input())
P = int(input())

adj = {i : [] for i in range(1, N+1)}
vis = {1:True}

for i in range(P):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

def go(curr):
    if not adj[curr] : # 해당 인접리스트가 비었다면 종료
        return 0

    res = 0

    for i in adj[curr]:
        if i in vis:
            continue

        vis[i] = True
        res += (go(i) + 1)
        
    return res

print(go(1))