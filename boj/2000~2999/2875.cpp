//간단한 그리디 문제입니다.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m, k;
    int team;

    cin>>n>>m>>k;
    team = min(n/2, m);
    k -= (n-team*2) + (m-team);
    team = (k>0 ? team-ceil((double)k/3) : team);
    cout<<team;

    return 0;
}
