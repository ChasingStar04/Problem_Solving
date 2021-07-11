#가장 높은 단위의 동전으로 값을 지불합니다.
n = int(input())
money = 1000-n;
cnt = 0;
while money>0:
    if money>=500:
        money -= 500
    elif money>=100:
        money -= 100
    elif money>=50:
        money -= 50
    elif money>=10:
        money -= 10
    elif money>=5:
        money -= 5
    else:
        money -= 1
    cnt += 1
print(cnt)
