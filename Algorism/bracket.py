
def confirm(N,l):  
    for i in range(len(N)):
        if N[i]=="(" or N[i]=="{" or N[i]=="[":
            l.append(N[i])
        if len(l) ==0:      
            if N[i]==")" or N[i]=="}" or N[i]=="]":
                return 0
        else:
            if N[i]==")":
                if l.pop()!="(":
                    return 0
            elif N[i]=="}":
                if l.pop()!="{":
                    return 0
            elif N[i]=="]":
                if l.pop()!="[":
                    return 0
    if len(l)!=0:
        return 0
    return 1
                
T = int(input())              
for i in range(T):
    li=[]
    Num = input()  
    if confirm(Num,li)==0:
        print("NO")
    else:
        print("YES")

