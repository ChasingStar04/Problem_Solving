#두 배열의 앞자리부터 하나씩 비교해서 더 작은 값을 출력합니다.
n, m = map(int, input().split())
list1 = []
list2 = []

list1 = list(map(int, input().split()))
list2 = list(map(int, input().split()))

i = 0
j = 0
while i<n or j<m:
    if j>=m or (i<n and list1[i]<list2[j]):
        print(list1[i], end=' ')
        i += 1
    else:
        print(list2[j], end=' ')
        j += 1
