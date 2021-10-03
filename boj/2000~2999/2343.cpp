//m개의 블루레이에 나눠담을 수 있는 최소의 크기를 이진 탐색을 이용하여 찾습니다.
#include <iostream>

using namespace std;

int length[100010];
int n, m;

bool Can(int len)
{
    int now = 0, cnt = 1;
    for (int i=0; i<n; i++)
    {
        if (now+length[i]<=len)
            now += length[i];
        else if (length[i]<=len)
        {
            cnt++;
            now = length[i];
        }
        else
            return false;
    }

    return (cnt<=m);
}

int main()
{
    cin>>n>>m;
    for (int i=0; i<n; i++)
        cin>>length[i];
    
    int low = 0, high = 1000000000;
    int mid;
    while (low<high)
    {
        mid = (low+high)/2;

        if (Can(mid))
            high = mid;
        else
            low = mid+1;
    }
    cout<<high;

    return 0;
}
