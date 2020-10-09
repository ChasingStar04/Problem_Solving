/*
'('이 들어오면 fr을 +1하고
')'가 들어오면 fr을 -1합니다.

이 과정중 fr이 0 미만이 되거나 마지막에 fr이 0이 아니면 NO,
아니라면 YES를 출력합니다.
*/
#include <stdio.h>
#include <string.h>

int fr;

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        int fr = 0, yes_or_no = 1;
        char str[100] = {0};
        scanf("%s", str);
        int len=strlen(str);
        for(int i=0; i<len; i++)
        {
            if(str[i]=='(')  fr++;
            else fr--;
            if(fr<0)
            {
                yes_or_no = 0;
                break;
            }
        }
        if(yes_or_no && fr==0)  puts("YES");
        else  puts("NO");
    }
    return 0;
}
