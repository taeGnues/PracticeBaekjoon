N = int(input())
dp = {0:0, 1:1, 2:2}

for i in range(3, N+1):
    dp[i] = dp[i-1] + dp[i-2]

print(dp[N]%10007)