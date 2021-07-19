T = int(input())
l = []
for i in range(T):
    data = list(map(int,input().split()))
    query = list(map(int,input().split()))
    answer = []
    for q in query:
        left = 0
        right = len(data)-1
        while left <= right:
            mid = (left + right)//2
            if data[mid] == q:
                break
            elif data[mid] > q:
                right = mid -1
            elif data[mid] < q:
                left = mid + 1
        if left > right:
            answer.append(-1)
        else:
            answer.append(mid)
            #쿼리가 중간의 값보다 클때, 왼쪽 범위 제거, 작을 때, 오른쪽 범위 제거
            #같을 때, 찾았으니 더 이상 탐색 X
            
    print(*answer)
