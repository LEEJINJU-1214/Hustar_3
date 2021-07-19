T = int(input())              
for i in range(T):
    N,M  = map(int,input().split())
    l = [[]for _ in range(N)]
    for j in range(M):
        u, v= map(int,input().split())
        l[u].append(v)
        l[v].append(u)
        l[u].sort()
        l[v].sort()
    for row in range(N):
        for col in range(len(l[row])):   
            print(l[row][col],end=' ')
        print()
        
            