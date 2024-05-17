import sys

N = int(sys.stdin.readline())

# 왼 -> 오  
# 단어 첫글자가 이미 단축키? -> 아니면 그 알파벳 단축키 지정.

# 모든 단어 첫글자 이미 지정? -> 단축키로 지정안된거 단축키 지정

# 어떠한 것도 단축키 지정할 수 없으면 -> 그냥 두기.

#  N번째 옵션까지.

shorcuts = {}

def check(option_words):
    # 1. 첫번째 단어 유무 체크.

    ow_idx = 0

    for idx, ow in enumerate(option_words):
        capt = ow[0].upper()
        if capt not in shorcuts:
            shorcuts[capt] = option_words
            ow_idx = idx
            postfix = option_words[ow_idx][1:] if len(option_words[ow_idx])>=2 else ''
            option_words[ow_idx] = '['+option_words[ow_idx][0]+']' + postfix
            print(' '.join(option_words))
            return


    # 2. 첫번째 단어가 있다면, 그외 문자로 선택하기.

    ow_idx = 0
    o_idx = 0
    
    for idx, ow in enumerate(option_words):
        for i, o in enumerate(ow):
            capt = o.upper()
            if capt not in shorcuts: 
                shorcuts[capt] = option_words
                ow_idx = idx
                o_idx = i 
                t = list(option_words[ow_idx])
                t[o_idx] = '['+option_words[ow_idx][o_idx]+']'
                option_words[ow_idx] = ''.join(t)
                
                print(' '.join(option_words))
                return
    
    # 3. 아무것도 안된다면, 그대로 두기.
    print(' '.join(option_words))
    return

for i in range(N):
    option_words = sys.stdin.readline().rstrip().split()
    check(option_words)

    