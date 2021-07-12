//생각해보면, 자신의 왼쪽의 있는 수 중 선택된 수의 총합은 항상 같습니다.
//그러므로 그냥 큰 순서대로 k개 고르면 됩니다.
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int result = 0;
    int arr[5010] = {0};
    int n, k;
    
    cin>>n>>k;
    for (int i=0; i<n; i++)
        cin>>arr[i];
    
    sort(arr, arr+n, greater<>());
    for (int i=0; i<k; i++)
        result += arr[i]-i;
    cout<<result;

    return 0;
}
