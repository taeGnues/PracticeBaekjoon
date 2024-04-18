T = int(input())

for _ in range(T):
    N = int(input())
    

    if N == 0:
        print(0)
    else:
        clothes = {}
        for _ in range(N):
            name, category = input().split()
            if category not in clothes :
                clothes[category] = [name]
            else:
                clothes[category].append(name)
        

            # (해당옷종류의 개수 + 1(아무것도 안입었을때))*... -1(아무것도 안입엇을때)
            ans = 1
        for k, v in clothes.items():
            ans*=(len(v)+1)
        print(ans-1)
    
