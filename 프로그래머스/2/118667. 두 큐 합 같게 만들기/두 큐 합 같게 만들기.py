from collections import deque
def solution(queue1, queue2):
    one = deque(queue1)
    two = deque(queue2)
    
    onesum = sum(queue1)
    twosum = sum(queue2)
    
    if (onesum + twosum) % 2 != 0:  # 합이 짝수여야 둘의 길이가 같아지니
        return -1
    
    goal = (onesum + twosum) // 2
    
    max_trial = len(one)*2 + 2   # +1 대신 +2 를 해서 for문을 1번 더 돌려야 정답이 된다.
    # 근데 아무리 생각해도 + 1 을 해도 동작해야한다고 생각함
    # 질문 게시판의 반례는 [1,1,1,1], [1,1,7,1] 인 경우인데 손으로 그렸을 때도 9번이먼 동작 완료...

    count = 0
    
    # 반복문, 그리디?
    for _ in range(max_trial):
        if onesum > goal:
            temp = one.popleft()
            two.append(temp)
            onesum -= temp
            twosum += temp
            count += 1
            
        elif twosum > goal:
            temp2 = two.popleft()
            one.append(temp2)
            onesum += temp2
            twosum -= temp2
            count += 1
        
        if onesum == goal and twosum == goal:
            return count
        
    return -1