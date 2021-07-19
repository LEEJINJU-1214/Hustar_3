import collections
T  = int(input())
for _ in range(T):
    queue = collections.deque([])
    l = input().split()
    for i in range(len(l)):
        if len(queue)==0:
            queue.append(l[i])
        else:
            a = queue.popleft()
            if a != l[i]:
                queue.appendleft(a)
                queue.append(l[i])
    if len(queue)==0:
        print("NO")
    else:
        print("YES")
                
                
    
    
    
    
    