def dbro(l,n):
    DP = [0]*len(l)
    for i in range(1,n+1):
        if i==1:
            DP[i] = l[i]
        elif i%2 == 1:
            DP[i] = max(DP[i-1],DP[i-2])+l[i]
        else:
            DP[i] = max(DP[i-1],DP[i-2],DP[i//2])+l[i]
            
    return DP[n]

testnum = int(input())
for _ in range(testnum):
    n = int(input())
    lis = list(map(int, input().split()))
    lis = [0]+lis
    print(dbro(lis, n))