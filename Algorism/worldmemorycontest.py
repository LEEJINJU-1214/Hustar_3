T = int(input())    
for _ in range(T): 
    n,m = map(int,input().split())
    data = []
    for j in range(n):
        data.append(list(map(int, input().split())))
    T = [[0]*m for i in range(n)]
    for i in range(n):
        for j in range(m):
            if i == 0 and j == 0:#시작 칸인 경우
                T[i][j] = data[i][j]
            elif i == 0:
                T[i][j] = T[i][j-1] + data[i][j]
            elif j == 0:
                T[i][j] = T[i-1][j] + data[i][j]
            else:
                T[i][j] = min(int(T[i][j-1]),int(T[i-1][j]),int(T[i-1][j-1]))+data[i][j]
    print(T[n-1][m-1])
        
        