#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    int sum = 0, mins = 99999;

    cin>>m>>n;
    for (int i=1; i<=100; i++)
    {
        int sq = i*i;
        if (sq>=m && sq<=n)
        {
            mins = min(sq, mins);
            sum += sq;
        }
    }
    if (sum==0)
        cout<<-1;
    else
        cout<<sum<<'\n'<<mins;
    
    return 0;
}
