'''
덱을 이용하여
배열을 진짜 회전시키는 대신 pop하는 방향을 바꾸어 해결할 수 있습니다.
'''
t = int(input())

for i in range(t):
    p = input()
    n = int(input())
    arr = input().split(',', n)
    if n>=1:
        arr[0] = arr[0][1:]
        arr[-1] = arr[-1][:-1]
    
    dq = list()
    direc = 0
    error = False
    for i in range(n):
        dq.append(int(arr[i]))
    for i in p:
        if i=='R':
            if direc==0:
                direc = -1
            else:
                direc = 0
        if i=='D':
            if not dq:
                print("error")
                error = True
                break
            dq.pop(direc)
    if not error:
        if direc==0:
            print(str(dq).replace(' ', ''))  #리스트를 출력할 때 생기는 공백을 없애고 출력
        else:
            print(str(dq[::-1]).replace(' ', ''))
