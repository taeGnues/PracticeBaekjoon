N, M = map(int, input().split())
trees = sorted(list(map(int, input().split())))

total = 0
lo = 0
hi = max(trees)

while lo <= hi :
    mid= (lo+hi)//2
    total = sum(list(map(lambda x: x-mid if x-mid>=0 else 0, trees)))
    

    if total >= M :
        lo = mid+1
    else:
        hi = mid-1

print(hi)

