'''
스택을 만들어서 '('나 '['가 들어오면 push합니다
')'나 ']'가 들어왔을 때 스택이 비었거나 pop한 값이 짝이 맞지 않는다면 no
마지막에 스택이 비어있지 않으면 no
나머지 경우에 yes를 반환합니다
'''
small_cnt = 0
big_cnt = 0

while True:
    str = input()
    if str=='.':
        break
    
    stk = []
    yes_or_no = 'yes'
    for i in str:
        if i=='(':
            stk.append(i)
        if i=='[':
            stk.append(i)
        if i==')':
            if len(stk)==0:
                yes_or_no = 'no'
                break
            if stk.pop()!='(':
                yes_or_no = 'no'
                break
        if i==']':
            if len(stk)==0:
                yes_or_no = 'no'
                break
            if stk.pop()!='[':
                yes_or_no = 'no'
                break
    if len(stk)!=0:
        yes_or_no = 'no'
    print(yes_or_no)