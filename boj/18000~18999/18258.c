//c언어에서 배열로 큐를 구현해봅시다.
#include <stdio.h>
#include <string.h>

struct Queue
{
    int fr;
    int re;
    int data[2000000];
}  que;

void Push(int num){que.data[que.re++] = num;}
int Empty(){return que.re-que.fr==0;}
int Pop(){return Empty() ? -1:que.data[que.fr++];}
int Size(){return que.re-que.fr;}
int Front(){return Empty() ? -1:que.data[que.fr];}
int Back(){return Empty() ? -1:que.data[que.re-1];}

int main()
{
    int n;

    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        char command[10] = {0};
        scanf("%s", command);

        if(strcmp(command, "push")==0)
        {
            int num;
            scanf("%d", &num);
            Push(num);
        }
        else if(strcmp(command, "pop")==0)
            printf("%d\n", Pop());
        else if(strcmp(command, "size")==0)
            printf("%d\n", Size());
        else if(strcmp(command, "empty")==0)
            printf("%d\n", Empty());
        else if(strcmp(command, "front")==0)
            printf("%d\n", Front());
        else if(strcmp(command, "back")==0)
            printf("%d\n", Back());
    }

    return 0;
}
