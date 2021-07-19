T = int(input())
l = []
        
for i in range(T):
    data = list(map(int,input().split()))
    query = list(map(int,input().split()))
    answer = []
    for q in query:
        Start = 0
        End = len(data)-1
        while Start <= End:
            mid = (Start + End)//2
            if data[End]<=q:
                mid = End
                break
            elif data[Start]>=q:
                mid = Start
                break
            elif data[mid]==q:
                break
            if mid == Start or mid ==End :
                if q>data[mid]:
                    x = data[End]-q
                    y = q - data[mid]
                
                    if x<y:
                        mid = End
                        break
                    else:
                        break
                else:
                    x = data[mid] - q
                    y = q - data[Start]
                    if x<=y:
                        break
                    else:
                        mid = Start
                        break
            elif Start == End:
                mid  = Start
                break
            
            if data[mid] > q:
                End = mid
            else:
                Start = mid
            


        answer.append(data[mid])
            #쿼리가 중간의 값보다 클때, 왼쪽 범위 제거, 작을 때, 오른쪽 범위 제거
            #같을 때, 찾았으니 더 이상 탐색 X
            
    print(*answer)
