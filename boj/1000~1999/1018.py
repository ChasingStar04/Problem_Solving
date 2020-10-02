'''
만들 수 있는 체스판을 다 계산합니다
가로위치 * 세로위치 * 제일 왼쪽 위가 B인경우-W인경우
'''
n, m = input().split()
n = int(n)
m = int(m)

min_change = 0x3f3f3f3f

table  = []
for i in range(n):
    table.append(input())
for i in range(n-7):
    for j in range(m-7):
        change = 0
        for k in range(8):
            for l in range(8):
                if (k+l)%2==0 and table[i+k][j+l]!='W':
                    change += 1
                if (k+l)%2!=0 and table[i+k][j+l]!='B':
                    change += 1
        if change<min_change:
            min_change = change
        change = 0
        for k in range(8):
            for l in range(8):
                if (k+l)%2==0 and table[i+k][j+l]!='B':
                    change += 1
                if (k+l)%2!=0 and table[i+k][j+l]!='W':
                    change += 1
        if change<min_change:
            min_change = change
print(min_change)