from collections import deque

N, K = map(int, input().split())

visit = {}

q = deque()
q.append(N)
visit[N]=0

if N == K:
    print(0)
    exit()

while q:
    cur = q.popleft()

    for i in [cur+1, cur-1, 2*cur] :
        nxt = i
        if nxt==K:
            print(visit[cur]+1)
            exit()

        if nxt in visit or nxt < 0 or nxt > 200002:
            continue
    
        q.append(nxt)
        visit[nxt] = visit[cur]+1

    