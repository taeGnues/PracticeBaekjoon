import itertools



def solution(orders, course):
    
    possible_menus = {}
    for s in orders:
        tmp = []
        for c in course:
            if c <= len(s):
                tmp.append(list(itertools.combinations(s, c)))
                
        for t in tmp:
            for c in t:
                c = ''.join(sorted(list(c)))
                if c in possible_menus:
                    possible_menus[c]+=1
                else:
                    possible_menus[c]=1
    ans_dic = {i:{} for i in course}
    
    for k, v in possible_menus.items(): # v가 가장 큰거 중에 선택하기.
        if len(k) in course : 
            ans_dic[len(k)][k] = v
    # print(ans_dic)
    
    
    ans = {i:[] for i in course}
    for k, v in ans_dic.items():
        if v :
            mx = max(v.values())
            if mx == 1 : # 가능 코스 메뉴개수가 1개일 때 생략
                continue
            
            for l, m in v.items():
                if mx==m:
                    ans[k].append(l)
            
    answer = []
    for k, v in ans.items():
        if v :
            for t in v :
                answer.append(t)
    return sorted(answer)