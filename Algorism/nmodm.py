def Power(n,k,m):
    if k==0:
        return 1
    if k==1:
        return n
    half = Power(n,k//2,m)
    if k%2 == 0:
        return (half*half)%m
    else:
        return (half*half*n)%m
T = int(input())
for i in range(T):
    n,k,m = map(int,input().split())
    print(Power(n,k,m))
    