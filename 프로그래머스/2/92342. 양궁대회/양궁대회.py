def solution(n, info):
    answer = None
    max_diff_score = -1
    
    

    # 1. 각 경우마다 어피치를 이기는지, 해당 어피치의 점수와의 차이를 확인함.
    def check_score_diff(curr):
        appeach = 0
        lion = 0
        
        for i in range(11):
            if info[i] == 0 and curr[i] == 0 :
                continue
            if info[i] == 0 and curr[i] > 0:
                lion+=(10-i)
            elif info[i] >= curr[i]: # 어피치가 10-i 점의 과녁에 맞춘 개수가 같거나 더 많다면.
                appeach+=(10-i)
            elif info[i] < curr[i]: # 라이언이 더 크다면.
                lion+=(10-i)
        
        diff_score = lion-appeach
        
        # 어피치가 이겼거나 max_diff_score을 갱신 못하면 무시
        nonlocal max_diff_score
        nonlocal answer
        
        if diff_score <= 0 or max_diff_score > diff_score : 
            return
        
        # 예외처리 필수 !!!!
        if max_diff_score == diff_score:
            for i in range(10, -1, -1):
                if answer[i] < curr[i] :
                    answer = curr[:]
                    break
                elif answer[i] > curr[i]:
                    break
        else:
            # max_diff_score 및 answer 갱신
            max_diff_score = diff_score
            answer = curr[:]
        
        return
    
    # 1. n발의 화살을 0~10점 사이에 분배하는 경우 확인
    def go(times, curr):
        if times == 0 and len(curr) == 11: # 0점부터 10점까지 n발 화살 분배 완료.
            check_score_diff(curr) 
            return
        
        if len(curr) == 11:
            return
        
        for i in range(n, -1, -1): # 특정 점수에, 0발부터 n발까지 화살이 있을 수 있음.
            if times-i >= 0:
                curr.append(i)
                go(times-i, curr)
                curr.pop()
        
        return
    
    go(n, [])
    
    return [-1] if max_diff_score==-1 else answer

# 어피치 n발 -> 라이언 n발
# 점수 계산
# 가장 작은 원의 과녁 점수 10점. ~ 바깥쪽 0
# k점을 어피치 a발 / 라이언 b발 -> 더많은 화살을 k점에 맞힌 선수가 k점을 가져감.
# 최대 "k점"까지만 가져갈 수 있음.
# 최종점수 같으면 -> 어피치 우승.


# 어피치가 화살 n발 다 씀.
# 가장 큰 점수 차로 이기기 위해? -> n발의 화살을 어떤 과녁 점수에 쏴야할지 [10점, 9점 .. 0점]
# 화살의 개수 n

# 만약 가장 낮은 점수를 맞힌 개수를 더 많이 맞힌 경우를 return,.

# 실패 시 [-1]