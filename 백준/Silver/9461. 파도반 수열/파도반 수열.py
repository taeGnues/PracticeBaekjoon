T = int(input())

# 1 1 1 2 2 3 4 5 7 9
# f(0) f(1) f(2) f(3)
# f(3) = f(1) + f(0)
# f(n) = f(n-2) + f(n-3) (n>=3)

dp = {1:1, 2:1, 3:1}
for _ in range(T):
    N = int(input())

    def go(n):
        if n in dp :
            return dp[n]
        
        dp[n] = go(n-2) + go(n-3)

        return dp[n]
    print(go(N))
        
