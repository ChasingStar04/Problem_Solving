//DFS를 이용합니다. 고른 숫자는 문자열로 보내줍니다.
#include <iostream>
#include <string>

using namespace std;

int n, m;
bool check[9];

void Solve(string s)
{
    if (s.length()==m)
    {
        for (char &i : s)
            cout<<i<<' ';
        cout<<'\n';
        return;
    }
    else
    {
        for (int i=1; i<=n; i++)
        {
            if (!check[i])
            {
                check[i] = true;
                Solve(s+(char)('0'+i));
                check[i] = false;
            }
        }
    }
    return;
}

int main()
{
    cin>>n>>m;

    for (int i=1; i<=n; i++)
    {
        string s;
        s += '0'+i;
        check[i] = true;
        Solve(s);
        check[i] = false;
    }

    return 0;
}
