T = int(input())    
def cmp(x):
    return x[0]/x[1]
for i in range(T): 
    N,C = map(int,input().split())
    S=[]
    max = 0
    for j in range(N):
        S.append(tuple(map(int,input().split())))
    S.sort(key = cmp, reverse = True)
    for j in range(N):
        if C - S[j][1]>=0:
            C -= S[j][1]
            max += S[j][0]
        else:
            max +=(S[j][0]) / (S[j][1]/C)
            C = 0
            break
    print(int(max))
        

        
        