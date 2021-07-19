import heapq 
T = int(input())
for i in range(T):
    N = int(input())
    hq = []
    for i in range(N):
        a=int(input())
        if a == -1:
            print(heapq.heappop(hq))
        else:
            heapq.heappush(hq, a)
            
