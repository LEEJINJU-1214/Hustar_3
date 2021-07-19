#밑에서 부터 올라옴
T = int(input())
for i in range(T):
    n,m = map(int, input().split())
    data = []
    for i in range(n):
        data.append(list(map(int, input().split())))
    
    T = [[0]*m for i in range(n)]
    for i in range(n):
        for j in range(m):
            if i == 0 and j == 0:#시작 칸인 경우 : 자기자신
                T[i][j] = data[i][j]
            elif i==0:#제일 위쪽 줄인 경우 왼쪽에서밖에 올 수 없다
                T[i][j] = T[i][j-1] + data[i][j]
            elif j == 0:#제일 왼쪽 줄인 경우 위쪽에서밖에 올 수 없다
                T[i][j] = T[i-1][j] + data[i][j]
            else:#그 외의 경우
                T[i][j] = max(T[i][j-1],T[i-1][j])+data[i][j]
    print(T[n-1][m-1])#정답 출력