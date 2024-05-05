import sys

T = int(sys.stdin.readline())

# ESTJ (1111) INFP (0000) 심리적 거리는? => 1111^0000 =
#  1111 -> 4
# (x >> 2*i) & 1 => 자리수 체크용
for _ in range(T):
    N = int(sys.stdin.readline())
    MBTIS = list(sys.stdin.readline().split())

    
    def cal(arr): # 심리적 거리 계산용
        if arr[0]==arr[1] and arr[1]==arr[2] and arr[0]==arr[2]:
            return 0 # 모두 같은 mbti면 0
        res = 0
        for i in range(4): # 서로 다른게 한개라도 있으면 +1
            if arr[0][i] != arr[1][i] : res +=1
            if arr[1][i] != arr[2][i] : res +=1
            if arr[2][i] != arr[0][i] : res +=1
        return res
    
    if N > 32: # 비둘기집 원리 
        print(0)
    else:
        min_distance = 12
        def go(curr, st): # nC3
            global min_distance
            if len(curr) == 3 :
                return cal(curr)
            
            for i in range(st+1, len(MBTIS)):
                curr.append(MBTIS[i])
                min_distance = min(go(curr, i), min_distance)
                curr.pop()
            
            return min_distance
        
        print(go([], -1))


