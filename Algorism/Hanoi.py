import heapq 

def hanoi(n, from_x, to_y, aux):
    if n==1:
        print(from_x,"->",to_y)
    else:
        hanoi(n-1, from_x, aux, to_y)
        print(from_x,"->",to_y)
        hanoi(n-1, aux,to_y,from_x)
        
T = int(input())
for i in range(T):
    N = int(input())
    hanoi(N,"A","C","B")
            