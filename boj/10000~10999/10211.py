#원소 a로 끝나는 최대 부분 배열은 a-1로 끝나는 최대 부분 배열에 a를 더하거나, a로 새로 시작하거나 둘 중 하나입니다.
#모든 원소에 대해 그 원소로 끝나는 최대 부분 배열을 구하고, 그중 최댓값을 저장해 출력합니다.
t = int(input())

for i in range(t):
    n = int(input())
    list1 = list(map(int, input().split()))
    res = -9999
    ssum = -9999
    for j in list1:
        ssum = ssum+j if ssum+j>j else j
        res = res if res>ssum else ssum
    print(res)
