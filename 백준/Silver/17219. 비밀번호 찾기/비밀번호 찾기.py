import sys

N, M = map(int, sys.stdin.readline().split())

# a A - . 
dic = {}
for _ in range(N):
    site, password = sys.stdin.readline().split()
    dic[site] = password

for _ in range(M):
    site = sys.stdin.readline().rstrip()
    print(dic[site])