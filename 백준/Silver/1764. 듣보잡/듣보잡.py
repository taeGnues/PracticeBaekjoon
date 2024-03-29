N, M = map(int, input().split())

not_listen = set()
not_see = set()

for i in range(N):
    name = input()
    not_listen.add(name)

for i in range(M):
    name = input()
    not_see.add(name)

ans = sorted(list(not_listen.intersection(not_see)))
print(len(ans))
for i in ans:
    print(i)