s = input()
signs = []
ops = []

tmp = ''
for i in s : # 입력받기
    if ord('0')<=ord(i)<=ord('9'):
        tmp+=i
    else:
        ops.append(tmp)
        signs.append(i)
        tmp=''

ops.append(tmp)

if len(ops)==1:
    print(ops[0])
else:
    chk = False
    for i in range(len(signs)):
        if signs[i]=='-':
            chk=False
            af = sum(int(ops[j]) for j in range(i+1, len(ops)))
            bf = sum(int(ops[j]) for j in range(0, i+1))
            print(bf-af)
            break
        else:
            chk=True

    if chk :
        print(sum(int(ops[j]) for j in range(0, len(ops))))