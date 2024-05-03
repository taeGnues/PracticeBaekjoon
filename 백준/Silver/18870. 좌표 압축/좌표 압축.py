import sys
# x1, x2, x3, x4 ...
# Xi는 , Xi > Xj을 만족하는 서로 다른 좌표 Xj의 개수와 같아야한다.

N = int(sys.stdin.readline())
X = list(map(int, sys.stdin.readline().split()))
sX = sorted([(X[i], i) for i in range(len(X))])
st = []
answer = [0]*len(X)

for s in sX:
    if st: # 스택이 안빌때
        if st[-1][0]==s[0]:# stack top과 넣으려는 s가 같다면
            answer[s[1]]=answer[st[-1][1]] # stack top과 같은 값 갖기
        else: # 만약 stack top보다 크다면
            answer[s[1]]=len(st) # 해당 스택 사이즈가 숫자가 됨.
            st.append(s) # 추가하기
        
    else: # 스택이 비어있을 때
        st.append(s) # 추가하고
        answer[s[1]] = 0 # 해당 인덱스 표시

print(*answer)