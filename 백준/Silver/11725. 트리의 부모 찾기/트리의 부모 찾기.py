from collections import deque
N  = int(input())
dic = {i: [] for i in range(1, N+1)}
pdic = {}

visit = []
def go(v):
    for i in dic[v]:
        if i not in visit:
            pdic[i] = v # v를 i의 부모로 설정하기
            visit.append(i) # 방문 표시
            go(i)

    return

pdic2={}
def bfs():
    q = deque([1])
    vs = [0]*(10**5+1)
    vs[1] = True

    while q :
        c = q.popleft()
        for i in dic[c] :
            if vs[i] :
                continue
            pdic2[i]=c
            q.append(i)
            vs[i]=True


for i in range(N-1):
    n, m = map(int, input().split())
    dic[n].append(m)
    dic[m].append(n)

bfs()

for i in range(2, N+1):
    print(pdic2[i])

    



    
