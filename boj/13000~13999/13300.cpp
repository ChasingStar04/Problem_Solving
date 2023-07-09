#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    int student[2][6] = {0};
    int res = 0;

    cin>>n>>k;
    for (int i=0; i<n; i++)
    {
        int s, y;
        cin>>s>>y;
        student[s][y-1]++;
    }

    for (int i=0; i<2; i++)
    {
        for (int j=0; j<6; j++)
            res += ceil((double)student[i][j]/k);
    }
    cout<<res;

    return 0;
}
