T = int(input())

mem = {0 : (1,0), 1 : (0,1)}

def go(n) :
    if n in mem :
        return mem[n]
    
    t1 = go(n-1)
    t2 = go(n-2)

    mem[n] = (t1[0] + t2[0], t1[1] + t2[1])

    return mem[n]
    

for i in range(T):
    n = int(input())
    go(n)
    print(mem[n][0], mem[n][1])
    


