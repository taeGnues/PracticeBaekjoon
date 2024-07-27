from itertools import combinations
from bisect import bisect_left

def solution(info, query):
    answer = []
    
    
    
    lang = ['java', 'python', 'cpp', '-']
    position = ['backend', 'frontend', '-']
    career = ['junior', 'senior', '-']
    food = ['pizza', 'chicken', '-']
    
    dic = {}
    for l in lang:
        for i in range(3):
            for j in range(3):
                for k in range(3):
                    dic[(l, position[i], career[j], food[k])] = []
    

    for i in info:
        l, p, c, f, score = i.split()
        
        score = int(score)
        
        dic[(l, p, c, f)].append(score)
        
        # 4C1
        dic[('-', p, c, f)].append(score)
        dic[(l, '-', c, f)].append(score)
        dic[(l, p, '-', f)].append(score)
        dic[(l, p, c, '-')].append(score)
        
        # 4C2
        for o in list(combinations([0,1,2,3], 2)):
            t = [l, p, c, f]
            t[o[0]] = '-'
            t[o[1]] = '-'
            dic[(t[0], t[1], t[2], t[3])].append(score)
            
        # 4C3
        dic[('-', '-', '-', f)].append(score)
        dic[(l, '-', '-', '-')].append(score)
        dic[('-', p, '-', '-')].append(score)
        dic[('-', '-', c, '-')].append(score)
        
        # 4C4
        dic[('-', '-', '-', '-')].append(score)
    
    for d in dic.values():
        d.sort()
    
    for q in query:
        qu = q.replace('and', '').split()
        n = 0
        if (qu[0], qu[1], qu[2], qu[3]) in dic:
            target_list = dic[(qu[0], qu[1], qu[2], qu[3])]
            idx = bisect_left(target_list, int(qu[4]))
            n += (len(target_list) - idx)
            
                
        answer.append(n)
        
        
    return answer