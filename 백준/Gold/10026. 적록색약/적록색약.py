from collections import deque

N = int(input())

dx = [-1, 1, 0, 0]
dy = [0,0,1,-1]

area_dic = {'R':0,'G':0, 'B':0} # 각각 구역이 몇개인지 확인
RG_cnt = 0
vis = {}
vis2 = {}

bd = [input() for _ in range(N)]

for i in range(N):
    for j in range(N):
        if (i, j) not in vis :
            q = deque()
            q.append((i,j))
            vis[(i,j)]=1
            chk_color = bd[i][j] # R, G, B 중 하나
            area_dic[chk_color]+=1 # 해당구역 개수 +1

            while q :
                cx, cy = q.popleft()

                for d in range(4):
                    nx = cx + dx[d]
                    ny = cy + dy[d]

                    if nx < 0 or ny < 0 or nx >= N or ny >= N:
                        continue
                    if bd[nx][ny]!=chk_color: 
                        continue
                    if (nx, ny) in vis:
                        continue
                    
                    q.append((nx,ny))
                    vis[(nx,ny)] = 1

        if (i, j) not in vis2 and (bd[i][j]=='G' or bd[i][j]=='R') :
            q = deque()
            q.append((i,j))
            vis2[(i,j)]=1
            RG_cnt+=1

            while q :
                cx, cy = q.popleft()

                for d in range(4):
                    nx = cx + dx[d]
                    ny = cy + dy[d]

                    if nx < 0 or ny < 0 or nx >= N or ny >= N:
                        continue
                    if bd[nx][ny]=='B': 
                        continue
                    if (nx, ny) in vis2:
                        continue
                    
                    q.append((nx,ny))
                    vis2[(nx,ny)] = 1
normal =  area_dic['R'] + area_dic['G'] +  area_dic['B']
blind = RG_cnt +  area_dic['B']

print(normal, blind)