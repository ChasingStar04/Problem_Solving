/*
벌통이 벌들 가운데 있다면, 벌은 양쪽 끝에, 벌통은 양쪽 끝을 제외한 곳 중 가장 값이 높은 곳에 두는게 가장 높은 값입니다.
벌통이 벌들 가운데 있지 않다면, 벌통은 한쪽 끝에, 벌 하나는 반대쪽 끝에 두고
남은 벌 하나를 움직이면서 가장 높은 값을 찾습니다.
*/
#include <iostream>

using namespace std;

int arr[100010];

int main()
{
    int n;
    int res = 0, cnt = 0;
    int middle_max = 0;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
        cnt += arr[i];
        if (i!=0 && i!=n-1)
            middle_max = max(middle_max, arr[i]);
    }
    
    res = max(res, cnt+middle_max-arr[0]-arr[n-1]); //벌통이 가운데 있는 경우
    
    int cnt2 = (cnt-arr[0]-arr[1])*2; //벌통이 오른쪽 끝에 있는 경우
    res = max(res, cnt2);
    int i = 2;
    while (i<n-1)
    {
        cnt2 -= arr[i]*2;
        cnt2 += arr[i-1];
        res = max(res, cnt2);
        i++;
    }
    
    cnt2 = (cnt-arr[n-1]-arr[n-2])*2; //벌통이 왼쪽 끝에 있는 경우
    res = max(res, cnt2);
    i = n-3;
    while (i>0)
    {
        cnt2 -= arr[i]*2;
        cnt2 += arr[i+1];
        res = max(res, cnt2);
        i--;
    }
    
    cout<<res;

    return 0;
}
