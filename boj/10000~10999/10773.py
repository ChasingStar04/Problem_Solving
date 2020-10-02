'''
스택을 만들어서 입력받은 수가 0이 아닐경우 push하고
0일경우 pop합니다
'''
k = int(input())
result = []
cnt = 0
for i in range(k):
    a = int(input())
    if a==0:
        result.pop()
    else:
        result.append(a)

for i in result:
    cnt += i
print(cnt)