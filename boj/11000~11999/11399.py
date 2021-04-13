#돈을 인출하는데 걸리는 시간이 적은 사람부터 인출합니다.
n = int(input())
list1 = list(map(int, input().split()))
cnt = 0
wait = 0

list1.sort()
for i in list1:
    cnt += wait+i
    wait += i
print(cnt)
