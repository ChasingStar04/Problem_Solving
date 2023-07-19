#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ans = 0;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        stack<char> stk;
        string s;

        cin>>s;
        for (char &c : s)
        {
            if (!stk.empty() && c==stk.top())
                stk.pop();
            else
                stk.push(c);
        }
        if (stk.empty())
            ans++;
    }

    cout<<ans;
    
    return 0;
}
