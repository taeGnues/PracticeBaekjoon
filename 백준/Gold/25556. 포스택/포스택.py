# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

def sol(nums):
    stack1 = []
    stack2 = []
    stack3 = []
    stack4 = []
    stacks = [stack1, stack2, stack3, stack4]


    for n in nums:
        check = True
        for i in stacks:
            if i and i[-1] < n : # stack이 비어있지 않고 해당 top보다 지금 넣으려는 값(n)이 더 크다면,
                i.append(n) # n을 추가함
                check=False
                break

            if not i : # 만약 해당 stack이 비어있으면
                i.append(n)
                check=False
                break
            
        if check:
            return False # 여기에 도달하면 위의 조건에도 성립되지 않으므로 종료시킴.
            
    return True


n = int(input())
arr = list(map(int, input().rstrip().split()))

if sol(nums=arr) :
    print("YES")
else :
    print("NO")
