#각 동전이 그 전 동전의 배수이므로 그리디로 풀 수 있습니다.
#값이 큰 동전부터 먼저 사용합니다.
n, k = map(int, input().split())
coin = []
cnt = 0

for i in range(n):
    coin.append(int(input()))

for i in coin[::-1]:
    cnt += k//i
    k %= i
print(cnt)
