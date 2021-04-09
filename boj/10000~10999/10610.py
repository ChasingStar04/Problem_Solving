#각 자리 숫자의 합이 3의 배수이고 숫자중에 0이 포함되어 있다면, 내림차순으로 정렬하여 출력합니다. 아니라면 -1을 출력합니다.
n = input()
n = list(map(int, list(n)))

allsum = 0
for i in n:
    allsum += i

n.sort(reverse=True)
if allsum%3==0 and n[-1]==0:
    for i in n:
        print(i, end='')
else:
    print(-1)
