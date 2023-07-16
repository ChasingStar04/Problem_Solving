//스택 이용. 자신보다 작은 항의 NGE를 자신으로 하고, 스택에서 뺌.
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int nge[1000010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num;
    stack<pair<int, int>> stk;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>num;
        while (!stk.empty() && stk.top().first<num)
        {
            nge[stk.top().second] = num;
            stk.pop();
        }
        stk.push({num, i});
    }
    while (!stk.empty())
    {
        nge[stk.top().second] = -1;
        stk.pop();
    }

    for (int i=0; i<n; i++)
        cout<<nge[i]<<' ';
    
    return 0;
}
