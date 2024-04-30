import sys

N = int(sys.stdin.readline())

s = {} # Dic

for _ in range(N):
    tmp = sys.stdin.readline()
    if ' ' in tmp :
        cmd, v = tmp.split()
    else :
        cmd = tmp.rstrip()
    
    if cmd == 'add':
        if int(v) not in s or s[int(v)] == False:
            s[int(v)] = True
    elif cmd == 'remove':
        if int(v) in s and s[int(v)] == True :
            s[int(v)] = False
    elif cmd == 'check':
        print(1) if int(v) in s and s[int(v)]==True else print(0)
    elif cmd == 'toggle':
        if int(v) in s and s[int(v)]==True:
            s[int(v)]=False
        else:
            s[int(v)]=True
    elif cmd=='all':
        s = {i:True for i in range(1, 21)}
    elif cmd =='empty':
        s = {}
    
    
