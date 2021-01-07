/*
풀이 1.
각 칸에 고여있는 물의 높이를 구한 후 모두 더합니다.
현재 칸에서 왼쪽에서 제일 높은 칸과 오른쪽에서 제일 높은 칸을 구한 후
둘 중 작은값에서 현재 칸의 높이를 뺀 값이 현재 칸에 고여있는 물의 높이입니다.
*/
#include <iostream>

using namespace std;

int main()
{
    int h, w;
    int arr[500];
    int cnt = 0;

    cin>>h>>w;
    for(int i=0; i<w; i++)
        cin>>arr[i];
    
    for(int i=0; i<w; i++)
    {
        int maxleft = arr[i], maxright = arr[i];
        
        for(int j=i; j>=0; j--)  //왼쪽 칸 중에 최댓값을 구합니다.
            maxleft = max(maxleft, arr[j]);
        for(int j=i; j<w; j++)  //오른쪽 칸 중에 최댓값을 구합니다.
            maxright = max(maxright, arr[j]);
        
        cnt += min(maxleft, maxright)-arr[i];
    }

    cout<<cnt;

    return 0;
}

/*
풀이 2.
스택을 활용한 방법입니다.
1) 스택 맨 위의 칸과 현재 칸 사이에 고여있는 빗물의 양을 구합니다.
2) 스택 맨 위의 칸을 새로운 바닥으로 합니다.
3) 스택 맨 위의 칸이 현재 칸보다 크지 않다면 pop한후 위의 과정을 반복하고, 아니라면 break합니다.

#include <iostream>
#include <stack>

using namespace std;

struct Data
{
    int x;  //x축
    int height;  //높이
};

int main()
{
    int h, w;
    int arr[500] = {0};
    int cnt = 0;
    stack<Data> stk;

    cin>>h>>w;
    for(int i=0; i<w; i++)
        cin>>arr[i];
    
    for(int i=0; i<w; i++)
    {
        int newh = arr[i];
        int bottom = 0;
        while(!stk.empty())
        {
            cnt += (i-stk.top().x-1)*(min(newh, stk.top().height)-bottom);
            bottom = stk.top().height;
            if(stk.top().height<=newh)
                stk.pop();
            else
                break;
        }
        
        stk.push({i, newh});
    }

    cout<<cnt;

    return 0;
}
*/
