from itertools import combinations

def solution(relation):
    # 후보키의 최대개수. (유일성 + 최소성)
    
    
    # n개 중에 1 .. 2... 3... n개까지 뽑아서 유일성을 확인함. 
    # 만약 한번이라도 유일성이 존재한다면, 후보키 후보가 됨.
    # 선택한 키에, 이미 존재하는 후보키가 존재한다면? -> 최소성 불만족.
    
    fields = [i for i in range(len(relation[0]))]
    alter_keys = []
    def check_min(c):
            # 1. 최소성 확인 (특정 키의 부분집합인지 확인.)
            for key in alter_keys:
                if key.issubset(c):
                    return False
            return True
    
    def check_unique(c):
        dic = {}
        for r in relation:
            k = ''
            for tmp_c in c:
                k+=str(r[tmp_c])

            if k not in dic:
                dic[k] = True
            else:
                return False
                    
        return True 
    
    for n in range(1, len(relation[0])+1): # 1.. 2.. 3.. 개 뽑기
        for c in list(combinations(fields, n)):
            
            c_set = set(c)
            
            # 최소성 확인. & 유일성 확인.
            if check_min(c_set) and check_unique(c_set):
                alter_keys.append(c_set)    

        
            
            
    return len(alter_keys)