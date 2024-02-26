def solution(clothes):
    answer = 1
    dic = {}
    for i in clothes:
        if dic.get(i[1]) :
            dic[i[1]].append(i[0])
        else :
            dic[i[1]] = [i[0]]
            
    
    for k in dic:
        print((len(dic[k])+1))
        answer *= (len(dic[k])+1)
    return answer-1