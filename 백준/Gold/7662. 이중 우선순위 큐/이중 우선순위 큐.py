import heapq, sys

# 데이터 삽입 연산 / 
# 데이터 삭제 연산 -> 우선순위 높은것 삭제 & 우선순위 낮은 것 삭제
input = sys.stdin.readline
T = int(input()) # 테스트데이터수

for _ in range(T):
    k = int(input()) # Q에 적용할 연산의 개수 k<=10**6
    mx_q = []
    mn_q = []
    q = {}

    for idx in range(k):
        c, n = input().split() 
        n = int(n)

        if c == 'I': # 삽입
            q[(n, idx)] = True
            heapq.heappush(mx_q, (-n, idx)) # mxq 삽입
            heapq.heappush(mn_q, (n, idx)) # mnq 삽입
        elif c == 'D' and not q: # 큐가 비어있는데 D면
            continue
        elif c == 'D' and n == 1 : # 최댓값 pop
            while mx_q :
                mxn, idx = heapq.heappop(mx_q)
                
                if (-mxn, idx) in q : # 해당값이 큐에 존재한다면 제거하고 종료
                    del q[(-mxn, idx)]
                    break
                
                # 해당값이 큐에 만약에 없다면 이미 제거된 값이므로, 다음 최대값을 찾아봄    

        elif c == 'D' and n == -1 : # 최솟값 pop
            while mn_q:
                mnn, idx = heapq.heappop(mn_q)

                if (mnn, idx) in q:
                    del q[(mnn, idx)]
                    break
    
    if not q:
        print('EMPTY')
    else:
        mxn, mnn = 0, 0
        while mx_q :
                mxn, idx = heapq.heappop(mx_q)
                
                if (-mxn, idx) in q : # 해당값이 큐에 존재한다면 제거하고 종료
                    break
        
        
        while mn_q:
                mnn, idx = heapq.heappop(mn_q)

                if (mnn, idx) in q:
                    break

        print(-mxn, mnn) 
    # D 1 q에서 최댓값 삭제
    # D -1 q에서 최솟값 삭제
    # D 비어있으면 연산 무시
    # I n q에 n삽입




