//볼 수 있는 정원 개수 대신, 보여지는 정원 개수를 센다.
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long cnt = 0;
    stack<int> stk;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        int num;
        
        cin>>num;
        while (!stk.empty() && stk.top()<=num)
            stk.pop();
        cnt += (long long)stk.size();
        stk.push(num);
    }
    cout<<cnt;

    return 0;
}
