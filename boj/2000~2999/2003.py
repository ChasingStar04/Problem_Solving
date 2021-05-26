#투 포인터 알고리즘을 이용하여 풀 수 있습니다.
n, m = map(int, input().split())
list1 = list(map(int, input().split()))
cnt = 0

psum = 0
start = 0
end = 0

while True:
    if psum>=m:
        psum -= list1[start]
        start += 1
    elif end==len(list1):
        break
    else:
        psum += list1[end]
        end += 1
    if psum==m:
        cnt += 1

print(cnt)
