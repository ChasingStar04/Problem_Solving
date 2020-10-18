'''
큐를 구현해서 큐가 빌 때까지
k-1번 만큼 push(pop())하고 print(pop())합니다.
'''
n, k = input().split()
n = int(n)
k = int(k)
que = list(range(1, n+1))

print('<', end='')
for i in range(n):
    for j in range(k-1):
        que.append(que.pop(0))
    if len(que)!=1:
        print(que.pop(0), end=', ')
    else:
        print(que.pop(0), end='')
print('>')
