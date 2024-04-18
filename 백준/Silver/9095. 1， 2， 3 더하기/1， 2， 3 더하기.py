nums = [1,2,3]

T = int(input())

for _ in range(T):
    N = int(input())
    dp = {}
    def go(n):
        if n > N :
            return 0

        if n == N :
            return 1
        
        if n in dp :
            return dp[n]
        
        dp[n] = 0
        for i in nums:
            dp[n] += go(n+i)
        
        return dp[n]
        
    print(go(0))

    
