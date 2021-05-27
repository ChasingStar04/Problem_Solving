//투 포인터 알고리즘으로 풀 수 있습니다.
#include <iostream>

using namespace std;

int arr[100010];

int TwoPointer(int n, int s)
{
    int sum = 0;
    int start = 0, end = 0;
    int ans = 0, len = 0;

    while (true)
    {
        if (sum>=s)
        {
            sum -= arr[start++];
            len--;
        }
        else if (end==n)
            break;
        else
        {
            sum += arr[end++];
            len++;
        }
        if (sum>=s)
            ans = (ans==0 || len<ans) ? len : ans;
    }

    return ans;
}

int main()
{
    int n, s;

    cin>>n>>s;
    for (int i=0; i<n; i++)
        cin>>arr[i];
    
    cout<<TwoPointer(n, s);

    return 0;
}
