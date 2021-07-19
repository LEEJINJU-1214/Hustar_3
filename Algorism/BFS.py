from collections import deque
T  = int(input())
for _ in range(T):
    N,M = map(int, input().split())
    List = [[]for _ in range(N)]
    for i in range(M):
        u,v = map(int, input().split())
        List[u].append(v)
    for i in range(N):
        List[i].sort()
    Check = [False]*N
    Queue = deque([0])
    count = 0
    while Queue:
        v = Queue.popleft()
        if Check[v]==True:
            continue      
        Check[v] = True
        print(v,end = ' ')
        for i in List[v]:
            if Check[i] == False:
                Queue.append(i)
    print("")