#1부터 순서대로 조건에 맞는지 검사합니다.
e, s, m = map(int, input().split())

i = 1
while True:
    emod = i%15 if i%15!=0 else 15
    smod = i%28 if i%28!=0 else 28
    mmod = i%19 if i%19!=0 else 19
    if emod==e and smod==s and mmod==m:
        print(i)
        break
    i += 1
