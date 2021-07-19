T = int(input())              
for i in range(T):
    N,M  = map(int,input().split())
    array = [[0 for col in range(N)] for row in range(N)]
    for j in range(M):
        u, v, c = map(int,input().split())
        array[u][v] += c
    for row in range(N):
        for col in range(N):
            print(array[row][col],end = ' ')
        print()
        
            