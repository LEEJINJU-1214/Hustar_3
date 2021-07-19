T = int(input())    
for _ in range(T):
    n = int(input())
    l = [0]*(n+1)
    for i in range(0,n+1):
        if i == 1:
            l[i] =  1
        elif i == 2:
            l[i] =  1
        elif i == 0:
            l[i] =  1
        else:
            l[i] = (l[i-1]+l[i-2])
    print(l[n])

    