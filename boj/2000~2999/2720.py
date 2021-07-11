#높은 단위부터 지불하고 지불한 양을 리스트에 저장합니다.
def solve(c):
    cnt = [0, 0, 0, 0]
    while c>0:
        if c>=25:
            c -= 25
            cnt[0] += 1
        elif c>=10:
            c -= 10
            cnt[1] += 1
        elif c>=5:
            c -= 5
            cnt[2] += 1
        else:
            c -= 1
            cnt[3] += 1
    print(cnt[0], cnt[1], cnt[2], cnt[3])

n = int(input())

for i in range(n):
    c = int(input())
    solve(c)
