#몫&나머지 연산은 세밀하게
t = int(input())

for i in range(t):
    h, w, n = map(int, input().split())
    hei = (n-1)%h + 1
    wei = (n-1)//h + 1

    ans = str(hei) + (str(wei) if wei>=10 else "0"+str(wei))
    print(ans)
