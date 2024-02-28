n = int(input())
arr = list(map(int, input().split()))
v = int(input())

dic = {}

for i in arr:
    if i in dic:
        dic[i] += 1
    else :
        dic[i] = 1

print(dic[v] if v in dic else 0)
    
