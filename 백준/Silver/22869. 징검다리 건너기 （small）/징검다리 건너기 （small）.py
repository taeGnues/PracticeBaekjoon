import sys
sys.setrecursionlimit(10**5)

# N개 돌 일렬 나열.
# A1 .. An까지 부여
# 왼쪽 돌 출발 오른쪽 돌로 건넘.
# 항상 오른쪽으로만 이동.
# i -> j 이동 시 (j-i) * (1+(Ai-Aj)) 만큼 힘 사용
# 돌 한번 건널시 최대힘 K
# 1 2 3 N

N, K = map(int, sys.stdin.readline().split())
bd = list(map(int, sys.stdin.readline().split()))
dp = {}

def go(curr):
    if curr in dp:
        return 0

    if curr == N-1 :
        print('YES')
        exit()

    dp[curr] = 0
    for j in range(curr+1, N): # i에서 시작해 j로 가능한 이동.
        strength = (j-curr)*(1+abs(bd[curr]-bd[j]))
        if strength > K:
            continue

        dp[curr] = go(j)
    
    return dp[curr]

go(0)

print('NO')