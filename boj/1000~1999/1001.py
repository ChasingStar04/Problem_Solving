'''
파이썬에서 한 줄에 여러개의 변수에 값을 입력받으려면
input().split()을 이용하면 됩니다.
input 함수로 입력받은 값을 기본적으로 문자형이므로
빼기 연산을 수행하기 위해 a와 b의 자료형을 숫자형으로 바꿔줍니다.
'''
a, b = input().split()
a = int(a)
b = int(b)
print(a-b)