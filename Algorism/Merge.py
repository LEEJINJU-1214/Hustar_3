T = int(input())    
for i in range(T):  
    list1 = list(map(int,input().split()))
    list2 = list(map(int,input().split()))
    l = list1+list2
    l.sort() 
    x = 0
    y = 0
    for i in range(len(l)):
        if x<len(list1):
            if l[i]==list1[x]:
                l[i] = 1
                x += 1
        if y<len(list2):
            if l[i]==list2[y]:
                l[i] = 2
                y +=1
    print(*l)

    