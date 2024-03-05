def solution(s):
    dic = {}
    ans = []

    for i in s :
        if i in dic :
            dic[i] += 1
        else :
            dic[i] = 1
    
    for k, v in dic.items() :
        if v == 1 :
            ans.append(k)
    ans.sort()
    answer=''.join(ans)
    return answer   