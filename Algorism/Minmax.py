N = int(input())
l = [0]*N
for i in range(N):
    l[i] = list(map(int, input().split()))
for i in range(N):
    print(max(l[i]) - min(l[i]))