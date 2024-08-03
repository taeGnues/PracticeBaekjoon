def sec_to_time(sec):
    h, m, s = sec // 3600, sec % 3600 // 60, sec % 60
    return f'{h:02}:{m:02}:{s:02}'

def time_to_sec(time):
    h, m, s = map(int, time.split(':'))
    return h*60*60+m*60+s

def solution(play_time, adv_time, logs):
    
    play = time_to_sec(play_time)
    adv = time_to_sec(adv_time)
    
    if play == adv:
        return '00:00:00'
    
    viewers = [0 for _ in range(100*60*60+1)] # 시간별 시청자 수. 
    
    for l in logs: # 시간대별 시청자 수 구하기
        st_t, ed_t = map(time_to_sec, l.split('-'))
        viewers[st_t] += 1
        viewers[ed_t] -= 1
        
    
    # 누적합 생성하기
    p = 0
    viewers[1] += (viewers[0] + viewers[0])
    for i in range(2, len(viewers)):
        viewers[i] += 2*viewers[i-1] - viewers[i-2]
        
    # t == 0. 길이가 adv로 주어질 때. 구간의 최대합 구하기.
    mx = viewers[adv]
    answer = 0
    
    for t in range(1, play-adv+1): 
        view = viewers[t + adv - 1] - viewers[t-1]
        if view > mx:
            mx = view
            answer = t
    
    
        
    return sec_to_time(answer)