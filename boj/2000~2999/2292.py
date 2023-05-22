#규칙을 찾는것이 중요!
n = int(input())

ans = 1
sum = 1

while n>sum:
    sum += 6*ans
    ans += 1

print(ans)
