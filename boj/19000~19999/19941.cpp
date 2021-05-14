//사람의 위치는 벡터에 넣고 햄버거의 위치는 큐에 넣습니다.
//왼쪽 사람부터 먹을 수 있는 햄버거 중에 제일 왼쪽에 있는 햄버거를 먹습니다.

#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    int n, k, cnt = 0;
    queue<int> que;
    vector<int> human;

    cin>>n>>k;
    for (int i=0; i<n; i++)
    {
        char c;
        scanf(" %c", &c);
        if (c=='H')
            que.push(i);
        else if (c=='P')
            human.push_back(i);
    }

    for (int& i : human)
    {
        while (!que.empty())
        {
            if (abs(i-que.front())<=k)
            {
                cnt++;
                que.pop();
                break;
            }
            else if(que.front()-i>k)
                break;
            que.pop();
        }
    }
    cout<<cnt;

    return 0;
}
