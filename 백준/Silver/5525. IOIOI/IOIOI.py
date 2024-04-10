N = int(input()) # Pn

M = int(input()) # S의 길이

S = input() # S

P = "" # Pn 생성하기
for i in range(2*N+1):
    if i%2==0:
        P+='I'
    else:
        P+='O'
ans=0

for i in range(M-len(P)+1):
    if P == S[i:i+len(P)]:
        ans+=1

print(ans)
