/*
수들은 정렬한 후 투 포인터 알고리즘을 활용해 값을 구합니다.
앞의 수를 s, 뒤의 수를 e로 두고
arr[e]-arr[s]가 m보다 작다면 e를 증가시킵니다.
그 후 result와 비교하여 최솟값을 갱신하고
s를 증가시킵니다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[100010];
    int n, m, s, e;
    int result = 0x3f3f3f3f;  //최솟값

    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    sort(arr, arr+n);
    s = 0, e = 1;
    while (s<n)
    {
        if(arr[e]-arr[s]<m)
        {
            e++;
            continue;
        }
        if(arr[e]-arr[s]==m)
        {
            result = m;
            break;
        }
        
        result = min(result, arr[e]-arr[s]);
        s++;
    }
    
    cout<<result;

    return 0;
}
