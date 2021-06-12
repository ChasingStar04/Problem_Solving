//최소비용으로 사는 방법은 우유를 비싼 순서대로 3개씩 묶어 구매하는 것입니다.
//그러므로 최소비용은 3의 배수번째 우유를 제외한 나머지를 다 더하면 됩니다.
#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

int main()
{
    int n;
    int ans = 0;

    cin>>n;
    for (int i=0; i<n; i++)
        cin>>arr[i];
    
    sort(arr, arr+n, greater<int>());
    for (int i=0; i<n; i++)
    {
        if (i%3!=2)
            ans += arr[i];
    }

    cout<<ans;

    return 0;
}
