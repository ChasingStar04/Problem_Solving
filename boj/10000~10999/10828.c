/*
스택을 구현하면 되는 간단한 문제입니다.
*/
#include <stdio.h>
#include <string.h>

int stack_table[100000], fr;

void push(int a)
{
    stack_table[fr++]=a;
}

int pop()
{
    if(fr)
        return stack_table[--fr];
    else
        return -1;
}

int size()
{
    return fr;
}

int empty()
{
    if(fr==0)
        return 1;
    else
        return 0;
}

int top()
{
    if(fr)
        return stack_table[fr-1];
    else
        return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        char s[10] = {0};
        int a;
        scanf("%s", s);
        if(strcmp(s, "push")==0)
        {
            scanf("%d", &a);
            push(a);
        }
        else if(strcmp(s, "pop")==0)
        {
            printf("%d\n", pop());
        }
        else if(strcmp(s, "size")==0)
        {
            printf("%d\n", size());
        }
        else if(strcmp(s, "empty")==0)
        {
            printf("%d\n", empty());
        }
        else if(strcmp(s, "top")==0)
        {
            printf("%d\n", top());
        }
    }

    return 0;
}
