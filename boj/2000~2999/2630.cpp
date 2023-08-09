#include <iostream>
#include <utility>

using namespace std;

int board[200][200];

pair<int, int> Func(int y, int x, int n)
{
    if (n==1)
    {
        if (board[y][x]==0) return make_pair(1, 0);
        else return make_pair(0, 1);
    }
    
    pair<int, int> r1, r2, r3, r4, res;
    r1 = Func(y, x, n/2);
    r2 = Func(y+n/2, x, n/2);
    r3 = Func(y, x+n/2, n/2);
    r4 = Func(y+n/2, x+n/2, n/2);
    res.first = r1.first+r2.first+r3.first+r4.first;
    res.second = r1.second+r2.second+r3.second+r4.second;

    if (res.first==0) return make_pair(0, 1);
    else if (res.second==0) return make_pair(1, 0);
    else return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cin>>board[i][j];
    }

    pair<int, int> res = Func(0, 0, n);
    cout<<res.first<<'\n';
    cout<<res.second<<'\n';

    return 0;
}
