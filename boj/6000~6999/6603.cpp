//백트래킹을 이용해서 6개 숫자의 조합을 만들어줍니다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lotto, choose;

void dfs(int lastidx)
{
    if (choose.size()>=6)
    {
        for (int& i : choose)
            cout<<i<<' ';
        cout<<'\n';
        return;
    }

    for (int i=lastidx+1; i<lotto.size(); i++)
    {
        if (find(choose.begin(), choose.end(), lotto[i])==choose.end())
        {
            choose.push_back(lotto[i]);
            dfs(i);
            choose.pop_back();
        }
    }

    return;
}

int main()
{
    int n;
    

    while (true)
    {
        cin>>n;
        if (n==0)
            break;
        
        lotto.clear();
        for (int i=0; i<n; i++)
        {
            int tmp;
            cin>>tmp;
            lotto.push_back(tmp);
        }

        for (int i=0; i<n; i++)
        {
            choose.push_back(lotto[i]);
            dfs(i);
            choose.pop_back();
        }
        cout<<'\n';
    }

    return 0;
}
