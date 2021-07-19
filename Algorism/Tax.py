t = int(input())
for _ in range(t):
    n = int(input())
    x = 0
    coins = [50000,10000,5000,1000,500,100]
    for i in range(len(coins)):      
        if x>=0 and n>=coins[i]:
            x += n//coins[i]
            n -= coins[i]*(n//coins[i])

    print(x)