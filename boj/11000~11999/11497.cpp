//높이순으로 정렬한 후 2칸간격으로 앞에서부터 1번째 - 3번째 - 5번째 - 7번째 - ... 이런식으로 배열합니다.
//그뒤에 짝수번호를 뒤에서부터 10번째 - 8번째 - 6번째 - ... 이런식으로 배열합니다.
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    int t;
    int arr[10010] = {0};

    cin>>t;
    for (int i=0; i<t; i++)
    {
        int n;
        int ans = 0;
        int last;

        cin>>n;
        for (int i=0; i<n; i++)
            cin>>arr[i];
        
        sort(arr, arr+n);

        last = arr[0];
        for (int j=2; j<n; j+=2)
        {
            ans = max(ans, abs(last-arr[j]));
            last = arr[j];
        }
        for (int j=(n%2==0 ? n-1: n-2); j>=0; j-=2)
        {
            ans = max(ans, abs(last-arr[j]));
            last = arr[j];
        }
        ans = max(ans, abs(last-arr[0]));

        cout<<ans<<'\n';
    }

    return 0;
}
