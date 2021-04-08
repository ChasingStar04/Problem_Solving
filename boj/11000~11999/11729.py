'''
a에 있는 n개의 원반을 b로 옮기는 과정은 3단계로 나눌 수 있습니다.
1. a에 있는 원반 n-1개를 c로 옮깁니다.
2. a에 있는 남은 원반 1개를 b로 옮깁니다.
3. c에 있는 원반 n-1개를 b로 옮깁니다.
'''

def another(a, b):
    if a+b==3:
        return 3
    elif a+b==4:
        return 2
    else:
        return 1

def move(n, a, b): #원판 n개를 a에서 b로 옮긴다
    if n==1:
        print(a, b)
    else:
        move(n-1, a, another(a, b))
        move(1, a, b)
        move(n-1, another(a, b), b)

n = int(input())

print(2**n-1)
move(n, 1, 3)
