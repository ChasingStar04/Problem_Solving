/*
덱을 활용해서 풀 수 있습니다.
초기값으로 덱에 1~n까지 순서대로 넣어줍니다.

그후 뽑아내려는 수가 들어오면 그 수를 제일 앞으로 보내야만 pop할 수 있으므로
왼쪽으로 이동하는 경로와 오른쪽으로 이동하는 경로 중 더 빠른 경로로 덱을 회전시키고
그 횟수만큼 카운트를 증가시킵니다.

왼쪽으로 회전하는 경우: PushBack(PopFront())
오른쪽으로 회전하는 경우: PushFront(PopBack())
*/
#include <iostream>

#define MAX_DEQUE_SIZE 55

using namespace std;

struct Deque
{
    int fr, re;
    int data[MAX_DEQUE_SIZE];
}  que;

void PushFront(int num)
{
    que.data[que.fr] = num;
    que.fr = (que.fr-1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
    return;
}

void PushBack(int num)
{
    que.re = (que.re+1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
    que.data[que.re] = num;
    return;
}

int PopFront()
{
    que.fr = (que.fr+1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
    return que.data[que.fr];
}

int PopBack()
{
    int prev = que.re;
    que.re = (que.re-1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
    return que.data[prev];
}

int Find(int num)
{
    int finder = (que.fr+1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
    while(que.data[finder]!=num)
        finder = (finder+1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
    return finder;
}

int main()
{
    int n, m, result = 0;
    
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        PushBack(i);
    for(int i=0; i<m; i++)
    {
        int num;
        cin>>num;

        int where = Find(num);
        int to_left = (where+MAX_DEQUE_SIZE-que.fr-1)%MAX_DEQUE_SIZE;
        int to_right = (que.re+MAX_DEQUE_SIZE-where+1)%MAX_DEQUE_SIZE;
        if(to_left<to_right)
        {
            for(int i=0; i<to_left; i++)
            {
                PushBack(PopFront());
                result++;
            }
            PopFront();
        }
        else
        {
            for(int i=0; i<to_right; i++)
            {
                PushFront(PopBack());
                result++;
            }
            PopFront();
        }
    }
    cout<<result;

    return 0;
}
