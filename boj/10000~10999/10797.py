#첫 줄에 입력받은 일의 자리 숫자와 자동자 일의자리 번호를 하나씩 비교하여 같으면 cnt를 1 증가시킵니다.
n = int(input())
list1 = map(int, input().split())

cnt = 0
for i in list1:
    if i==n:
        cnt += 1

print(cnt)
