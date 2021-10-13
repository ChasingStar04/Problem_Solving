//가능한 최소의 k 값을 이진 탐색을 이용하여 찾습니다.
#include <iostream>

using namespace std;

int arr[100010];
int n, m;

bool Can(int k)
{
    int cnt = 0, money = 0;
    for (int i=0; i<n; i++)
    {
        if (money>=arr[i])
            money -= arr[i];
        else if (k>=arr[i])
        {
            cnt++;
            money = k-arr[i];
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
        cin>>arr[i];
    
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
