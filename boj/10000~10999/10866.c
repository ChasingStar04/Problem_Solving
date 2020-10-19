//c언어로 덱을 구현해봅시다
#include <stdio.h>
#include <string.h>
#define MAX_DEQUE_SIZE 100100

struct Deque
{
    int fr, re;
    int data[MAX_DEQUE_SIZE];
}  que;

void Push_front(int num)
{
    que.data[que.fr] = num;
    que.fr = (que.fr-1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
    return;
}

void Push_back(int num)
{
    que.re = (que.re+1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
    que.data[que.re] = num;
    return;
}

int Empty()
{
    return (que.re+MAX_DEQUE_SIZE-que.fr)%MAX_DEQUE_SIZE==0;
}

int Pop_front()
{
    if(Empty())
        return -1;
    que.fr = (que.fr+1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
    return que.data[que.fr];
}

int Pop_back()
{
    if(Empty())
        return -1;
    int prev = que.re;
    que.re = (que.re-1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
    return que.data[prev];
}

int Size()
{
    return (que.re+MAX_DEQUE_SIZE-que.fr)%MAX_DEQUE_SIZE;
}

int Front()
{
    return Empty() ? -1:que.data[(que.fr+1)%MAX_DEQUE_SIZE];
}

int Back()
{
    return Empty() ? -1:que.data[que.re];
}

int main()
{
    int n;

    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        char command[12] = {0};
        scanf("%s", command);
        if(strcmp(command, "push_front")==0)
        {
            int num;
            scanf("%d", &num);
            Push_front(num);
        }
        else if(strcmp(command, "push_back")==0)
        {
            int num;
            scanf("%d", &num);
            Push_back(num);
        }
        else if(strcmp(command, "pop_front")==0)
            printf("%d\n", Pop_front());
        else if(strcmp(command, "pop_back")==0)
            printf("%d\n", Pop_back());
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
