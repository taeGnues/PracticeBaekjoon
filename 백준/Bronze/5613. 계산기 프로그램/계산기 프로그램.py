
ans = 0
s=''
st = []

while True:
    s = input()
    if s == '-' or s == '+' or s=='/' or s=='*' :
        st.append(s)
    elif s == '=' :
        ans = st.pop()
        break
    else : # 숫자일때
        if not st : # 스택이 비었다면
            st.append(int(s))
        else :
            op = st.pop()
            op1 = st.pop()
            op2 = int(s)
            if op == '-' :
                st.append(op1 - op2)
            elif op == '+' :
                st.append(op1 + op2)
            elif op == '*' :
                st.append(op1 * op2)
            elif op == '/' :
                st.append(op1 // op2)
            
    

print(ans)
