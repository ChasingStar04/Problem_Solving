//AC
//자신 앞의 기차와 뒤의 기차를 저장해 두어 처리합니다.
#include <iostream>
#include <queue>

using namespace std;

int front[100010];
int rear[100010];

int main()
{
    int n, q;
    cin>>n>>q;

    for (int i=1; i<=n; i++)
        front[i] = i;
    
    int query, x, y;
    for (int i=0; i<q; i++)
    {
        cin>>query;

        if (query==1)
        {
            cin>>x>>y;
            rear[x] = y;
            front[y] = x;
        }
        else if (query==2)
        {
            cin>>x>>y;
            rear[x] = 0;
            front[y] = y;
        }
        else if (query==3)
        {
            cin>>x;
            int car = x;
            while (front[car]!=car) car = front[car];

            int cnt = 0;
            queue<int> que;
            while (car!=0)
            {
                que.push(car);
                cnt++;
                car = rear[car];
            }

            cout<<cnt<<' ';
            while (!que.empty())
            {
                cout<<que.front()<<' ';
                que.pop();
            }
            cout<<'\n';
        }
    }

    return 0;
}
