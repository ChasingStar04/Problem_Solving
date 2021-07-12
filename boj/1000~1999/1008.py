#한 줄에 여러 변수를 입력받고 형변환까지 하려면, map 함수를 이용하면 됩니다.
a, b = map(int, input().split())
print(a/b)
