#dfs를 이용합니다.
def dfs(an, bn, cn):
    if visit[an][bn][cn]:
        return
    visit[an][bn][cn] = True
    if an==0:
        result.append(cn)

    move = min(an, b-bn) #a->b
    dfs(an-move, bn+move, cn)
    move = min(an, c-cn) #a->c
    dfs(an-move, bn, cn+move)
    move = min(bn, a-an) #b->a
    dfs(an+move, bn-move, cn)
    move = min(bn, c-cn) #b->c
    dfs(an, bn-move, cn+move)
    move = min(cn, a-an) #c->a
    dfs(an+move, bn, cn-move)
    move = min(cn, b-bn) #c->b
    dfs(an, bn+move, cn-move)
    
a, b, c = map(int, input().split())
result = []

visit = [[[False for k in range(201)] for j in range(201)] for i in range(201)]

dfs(0, 0, c)
result.sort()
for i in result:
    print(i, end=' ')
