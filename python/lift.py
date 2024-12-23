# import sys

# sys.stdout = open('output.txt','w')
# sys.stdin = open('input.txt','r')

import heapq

INF = float('inf')
def solve(sr,sc,dr,dc,m,n,l):
    if sr == dr and sc == dc:
        return 0
    
    if dr < n-1 and l[dr+1][dc] != 1:
        return INF

    def valid(x,y):
        return 0 <= x < m and 0 <= y < n
    
    visited = [[False]*n for _ in range(m)]
    heap = [(0,sr,sc)]

    while heap:
        steps, i,j = heapq.heappop(heap)

        if i == dr and j == dc:
            return steps-1

        if visited[i][j]:
                continue
        visited[i][j] = True
        
        # down
        if valid(i+1,j) and not visited[i+1][j]:
            # visited[i+1][j] = True 
            heapq.heappush(heap,(steps+1,i+1,j))
            if l[i][j] == 0 and l[i+1][j] == 0:
                continue

        # up
        if valid(i-1,j) and (l[i][j] == 1 or l[i-1][j] == 1 ) and not visited[i-1][j]:
            # visited[i-1][j] = True 
            heapq.heappush(heap,(steps+1,i-1,j))

        # right
        if valid(i,j+1) and not visited[i][j+1] and (i == m-1 or (l[i+1][j] == 1 and l[i+1][j+1] == 1)):
            # visited[i][j+1] = True 
            heapq.heappush(heap,(steps+1,i,j+1))

        # left
        if valid(i,j-1) and not visited[i][j-1] and (i == m-1 or (l[i+1][j] == 1 and l[i+1][j-1] == 1)):
            # visited[i][j-1] = True 
            heapq.heappush(heap,(steps+1,i,j-1))
        
            
    return INF


rows, cols = map(int, input().split())
l = []
for _ in range(rows):
    l.append(list(map(int, input().split())))
sr,sc = map(int, input().split())
I,J = map(int, input().split())

# print(rows, cols)
# print(l)
# print(sr,sc)
# print(I,J)

res = solve(sr,sc,I,J,rows, cols,l)
if res == INF:
    print('Impossible')
else:
    print(res)