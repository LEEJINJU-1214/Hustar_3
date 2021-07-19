import collections
T = int(input())
for i in range(T):
    N = int(input())
    queue = collections.deque([])
    for i in range(N):
        a=int(input())
        if a == -1:
            print(queue.popleft())
        else:
            queue.append(a)
            
