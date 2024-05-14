import sys
input = sys.stdin.readline

n, m = map(int, input().split())

graph = [[0] * (m + 1) for _ in range(n + 1)]
d = [[0] * (m + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    graph[i][1:] = list(map(int, input().split()))

for i in range(1, n + 1):
    for j in range(1, m + 1):
        d[i][j] = graph[i][j] + max(d[i - 1][j], d[i][j - 1])

print(d[-1][-1])