import sys

N, M = map(int, sys.stdin.readline().split())

acc = 0 
sums = {0:0} # 누적합 모음. [0] [:1] [:2] ...
nums = sys.stdin.readline().split()
for idx in range(1,N+1):
    acc+=int(nums[idx-1])
    sums[idx]=acc

for _ in range(M):
    st, ed = map(int, sys.stdin.readline().split())
    print(sums[ed] - sums[st-1])



