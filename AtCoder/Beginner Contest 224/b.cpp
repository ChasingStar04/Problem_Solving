//AC
//무지성으로 4중 for문 돌려서 모든 경우의 수를 검사했습니다.
#include <iostream>

using namespace std;

int main()
{
    int h, w;
    int arr[51][51] = {0};

    cin>>h>>w;
    for (int i=0; i<h; i++)
    {
        for (int j=0; j<w; j++)
            cin>>arr[i][j];
    }

    for (int i1=0; i1<h; i1++)
    {
        for (int i2=i1+1; i2<h; i2++)
        {
            for (int j1=0; j1<w; j1++)
            {
                for (int j2=j1+1; j2<w; j2++)
                    if (arr[i1][j1]+arr[i2][j2]>arr[i2][j1]+arr[i1][j2])
                    {
                        cout<<"No";
                        return 0;
                    }
            }
        }
    }
    cout<<"Yes";

    return 0;
}
