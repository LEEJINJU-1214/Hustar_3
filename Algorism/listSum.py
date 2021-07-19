N = int(input())
l = [0]*N
for i in range(N):
    l[i] = list(map(int, input().split()))
for i in range(N):
    sum = 0
    for j in range(len(l[i])):
        sum += l[i][j]
    print(sum)