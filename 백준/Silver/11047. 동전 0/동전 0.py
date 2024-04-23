import sys

N, K = map(int, sys.stdin.readline().split())

dp = {0:0}
coins = []

for _ in range(N): 
    c = int(sys.stdin.readline())
    coins.append(c)
    dp[c]=1

ans = 0
for c in coins[::-1]:
    if K>=c and K%c >= 0 :
        ans += K//c
        K = K%c

print(ans)

