# 모든 자연수는 4 혹은 그 이하 ㅔ곱수 합.
import sys, math
N = int(sys.stdin.readline())
rootN = int(math.sqrt(N))

dp = {}
max_value = 5

def go(n, level): 
    if level == 4 :
        if n == N:
            return 0
        else :
            return max_value
    
    if n == N:
        return 0
    
    if n > N :
        return max_value
    
    if n in dp:
        return dp[n]
    
    dp[n] = max_value
    for i in range(1, rootN+1):
        dp[n] = min(go(n+i**2, level+1)+1, dp[n])

    return dp[n]

print(go(0, 0))