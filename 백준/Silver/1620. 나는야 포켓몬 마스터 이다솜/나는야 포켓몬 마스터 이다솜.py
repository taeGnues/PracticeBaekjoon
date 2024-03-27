N, M = map(int, input().split())

dic1 = {}
dic2 = {}
questions = []

for i in range(1,N+1):
    poke_name = input()
    dic1[str(i)] = poke_name
    dic2[poke_name] = str(i)


for i in range(M):
    q = input()
    questions.append(q)

for i in questions:
    if i in dic1:
        print(dic1[i])
    elif i in dic2:
        print(dic2[i])
