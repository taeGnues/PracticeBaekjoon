
N = int(input())

MIN_VALUE = -10000000

score = {0:0}
dp = {}

for i in range(1, N+1):
    score[i] = int(input())

def go(curr, cnt):

    if cnt >= 3:
        return MIN_VALUE

    if curr > N :
        return MIN_VALUE
    
    if curr == N :
        return score[N]
    
    if (curr, cnt) in dp :
        return dp[(curr, cnt)]    

    dp[(curr, cnt)] = max(go(curr+1, cnt+1) + score[curr], go(curr+2, 1) + score[curr])
    
    return dp[(curr, cnt)]

print(go(0, 0))