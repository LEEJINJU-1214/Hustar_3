import heapq
T = int(input())    
for i in range(T):  
    INF = int(1e9)
    n,m = map(int,input().split())
    graph=[[] for _ in range(n+1)]
    distance_arr = [INF] * (n+1)
    for j in range(m):
        u,v,c = map(int,input().split())
        graph[u].append((c,v)) 
        
    
    distance_arr[0] = 0

    heap = []
    heapq.heappush(heap,(0,0))
    while heap:
        dist, cur = heapq.heappop(heap)
        if distance_arr[cur] < dist:
            continue
        for j in graph[cur]:
            cost = dist + j[0]
            next = j[1]
            if distance_arr[next] > cost :
                distance_arr[next] = cost
                heapq.heappush(heap,(cost,next))
    if distance_arr[n-1] == INF:
        print(-1)
    else:
        print(distance_arr[n-1])