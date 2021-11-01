//AC
//제일 처음 값과의 차와 나머지를 비교하여 맞는지 확인합니다.
#include <iostream>

using namespace std;

int b[10010][7];

int main()
{
    int n, m;
    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cin>>b[i][j];
    }

    int first = b[0][0], fj = (b[0][0]-1)%7;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if ((b[i][j]!=first+i*7+j) || (b[i][j]-1)%7<fj)
            {
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Yes";

    return 0;
}
