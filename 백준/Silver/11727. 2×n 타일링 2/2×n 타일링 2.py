import sys

N = int(sys.stdin.readline())
dp = {0:0, 1:1, 2:3} 

for i in range(3, N+1):
    dp[i] = dp[i-1] + dp[i-2] + dp[i-2]

print(dp[N]%10007)
