T = int(input())
for i in range(T):
    N = int(input())
    l = []
    for i in range(N):
        a=int(input())
        if a == -1:
            print(l.pop())
        else:
            l.append(a)
            
