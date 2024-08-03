def solution(p):
    answer = ''
    
    # 올바른 string 확인
    def check_correct_str(s):
        st = []
        for w in s:
            if w == ')':
                if not st:
                    return False
                elif st[-1] == '(':
                    st.pop()
            elif w == '(':
                st.append(w)
        
        if st:
            return False
        
        return True
    
    def change(s):
        tmp = ''
        for i in s:
            if i == ')':
                tmp += '('
            else:
                tmp += ')'
        return tmp
    
    # 균형잡힌 string 확인
    def check_balance_str(s):
        dic = {'(':0, ')':0}
        for w in s:
            dic[w]+=1
        
        return dic['('] == dic[')']
    # 해답
    def go(w):
        if not w:
            return ''
        
        for i in range(2, len(w)+1):
            u = w[:i] 
            v = w[i:]
    
            if check_balance_str(u) : # u가 균형잡힌 괄호 문자열인지 확인 
                if check_correct_str(u): # u가 올바른 괄호 문자열인지 확인
                    return u + go(v)
                
                else:
                    new_tmp = '(' + go(v) + ')'
                    new_u = u[1:-1]
                    new_uu = change(new_u)

                    return new_tmp + new_uu

    return go(p)


