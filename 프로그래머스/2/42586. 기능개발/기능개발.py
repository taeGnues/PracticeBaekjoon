from collections import deque

def solution(progresses, speeds):
    answer = []
    q = deque()
    for i in range(len(progresses)):
        q.append([progresses[i], speeds[i]])
    
    s = 0
    while s<len(progresses):
        a = 0
        for i in q:
            i[0] += i[1]
        
        while q:
            if q[0][0] >= 100 :
                a+=1
                s+=1
                q.popleft()
            else:
                break
        
        if a>0: 
            answer.append(a)
        
    return answer