'''
스택에 1부터 오름차순으로 push하고,
수를 넣은 직후 스택이 비어있지 않고 스택의 마지막원소가 입력된 수열(arr)과 같다면 pop합니다.
'''
n = int(input())
arr = []
arrp = 0
stk = []
result = []

for i in range(n):
    arr.append(int(input()))
for i in range(1, n+1):
    stk.append(i)
    result.append('+')
    while len(stk)!=0 and stk[-1]==arr[arrp]:  #스택의 마지막원소가 뺄 수와 같다면
        stk.pop()
        result.append('-')
        arrp += 1

if len(stk)==0:
    for i in result:
        print(i)
else:
    print("NO")
