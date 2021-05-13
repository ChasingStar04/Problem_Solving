/*
각 바구니에 담긴 공의 개수는 모두 달라야 하므로 최소로 넣을 수 있는 공의 개수는 k!개입니다.
n이 이보다 작으면 -1을 출력합니다.

k!개의 공을 배분한 후 남은 공들을 배분할 때는
공이 가장 많은 바구니부터 하나씩 받게 됩니다.
그러므로 (남은 공)%k==0 이라면 차이는 k-1이고,
아니라면 차이는 k입니다.
*/
#include <iostream>

using namespace std;

int main()
{
    int n, k;
    
    cin>>n>>k;
    if (n<k+k*(k-1)/2)
        cout<<-1;
    else
    {
        int newn = n-(k+k*(k-1)/2);
        if (newn%k==0)
            cout<<k-1;
        else
            cout<<k;
    }

    return 0;
}
