'''
스택을 구현하여 pop() -> push(pop())을 원소가 1개 남을 때까지 반복합니다.
pop을 파이썬 내 pop함수로 처리하면 시간 초과가 걸리기 때문에 fr을 +1 하는 것으로 처리했습니다.
'''
n = int(input())
que = list(range(1, n+1))
fr = 0

while len(que)-fr!=1:
    fr += 1
    que.append(que[fr])
    fr += 1
print(que[fr])
