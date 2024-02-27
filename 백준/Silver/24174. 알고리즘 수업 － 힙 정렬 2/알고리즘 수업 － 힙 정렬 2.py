	
# -*- coding: utf-8 -*- 

def heap_sort(li, n):
    global count
    build_min_heap(li, n); # 최소힙 생성
    for i in range(n, 1, -1):
        li[1], li[i] = li[i], li[1]
        count += 1
        if count == K:
            print(*li[1:])
            exit()
        heapify(li, 1, i - 1);
    

def build_min_heap(li, n):
    for i in range(n // 2, 0, -1):
        heapify(li, i, n)

def heapify(li, k, n):
    global count # 전역변수인 count를 사용하겠다고 선언.
    left, right = 2 * k, 2 * k + 1
    if right <= n:
        smaller = left if li[left] < li[right] else right
    elif left <= n:
        smaller = left
    else:
        return

    if li[smaller] < li[k]:
        li[k], li[smaller] = li[smaller], li[k]
        count += 1
        if count == K:
            print(*li[1:])
            exit()
        heapify(li, smaller, n);

N, K = map(int, input().split())
li = [0] + list(map(int, input().split())) # [0,1,2,3]
count = 0
heap_sort(li, N)
print(-1)