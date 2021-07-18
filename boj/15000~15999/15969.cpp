//정렬하거나, 최대값과 최솟값을 저장하는 변수를 만들어놓고 갱신합니다.
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[1010] = {0};
    int n;

    cin>>n;
    for (int i=0; i<n; i++)
        cin>>arr[i];
    
    sort(arr, arr+n);
    cout<<arr[n-1]-arr[0];

    return 0;
}
