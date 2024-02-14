//n일차에 1일차가 몇 번, 2일차가 몇 번 더해지는지 미리 테이블화
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[31][2] = {0};
    int d, k;

    cin>>d>>k;
    arr[1][0] = 1;
    arr[2][1] = 1;
    for (int i=3; i<=d; i++)
    {
        arr[i][0] = arr[i-2][0]+arr[i-1][0];
        arr[i][1] = arr[i-2][1]+arr[i-1][1];
    }
    for (int i=1; i<=k; i++)
    {
        int day1 = i*arr[d][0];
        if ((k-day1)%arr[d][1]!=0)
            continue;
        if ((k-day1)/arr[d][1]<i)
            continue;
        cout<<i<<'\n'<<(k-day1)/arr[d][1]<<'\n';
        break;
    }

    return 0;
}
