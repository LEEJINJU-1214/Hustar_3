import sys
sys.setrecursionlimit(10000000)

def DFS(v,List, Check):
    if Check[v]==True:
        return
    Check[v] = True
    print(v,end=' ')
    for i in List[v]:
        if Check[i] == False:
            DFS(i,List,Check)
            
    #List 방문 여부 등이 주어졌을 때 v를 방문 처리하고 다음 노드를 DFS 로 탐색하는 함수
    
t = int(input())
for _  in range(t):
    N,M = map(int, input().split())
    List = [[] for _ in range(N)]
    for i in range(M):
        u,v  = map(int, input().split())
        List[u].append(v)
        List[v].append(u)
    for i in range(N):
        List[i].sort()
    Check = [False]*N
    DFS(0,List,Check)
    
    print("")