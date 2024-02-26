from collections import deque

N, K = map(int, input().split())
dq = deque([i+1 for i in range(N)])
arr = []
while(len(dq)>0):
    dq.rotate(-(K-1))
    arr.append(dq.popleft())


print('<', end='')
for i in arr[:-1]:
    print(i, end=', ') 
print(str(arr[-1]) + '>')

