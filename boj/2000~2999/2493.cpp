/*
앞에 있는 탑 중 자신보다 작은 탑은 자신에 의해 가려지므로 고려할 가치가 없습니다.
새 탑의 높이가 들어오면 자신보다 작은 탑을 스택에서 비운 다음, 스택에 가장 위에 있는 탑(비어있다면 0)을 출력하고, 새 탑을 스택에 넣습니다.
*/
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    stack<pair<int, int>> stk;

    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int num;
        cin>>num;

        while (!stk.empty() && stk.top().first<num)
            stk.pop();
        if (stk.empty())
            cout<<"0 ";
        else
            cout<<stk.top().second<<' ';
        stk.push({num, i});
    }

    return 0;
}
