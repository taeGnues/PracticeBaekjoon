from collections import deque

def solution(numbers, direction):
    
    dq = deque(numbers)
    dq.rotate(1 if direction=="right" else -1)
    
    
    return list(dq)