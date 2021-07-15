//빨간 공을 왼쪽으로 옮겨 같은 색 공끼리 모으려면, 왼쪽에 붙어있지 않는 빨간 공의 개수만큼 옮겨야 합니다.
//빨간 공을 오른쪽으로 옮기는 경우, 파란 공을 왼쪽으로 옮기는 경우, 파란 공을 오른쪽으로 옮기는 경우도 비슷합니다.
//왼쪽과 오른쪽에 붙어있는 빨간 공, 파란 공의 개수를 센 후, 위 4가지 경우 중 가장 작은 경우를 찾습니다.
#include <iostream>

using namespace std;

char arr[500010];

int main()
{
    int n, r = 0, b = 0;
    int rs = 0, bs = 0, rl = 0, bl = 0;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        scanf(" %c", &arr[i]);
        if (arr[i]=='R') r++;
        else b++;
    }
    
    for (int i=0; i<n; i++)
    {
        if (arr[i]=='R' && (i==0 || arr[i]==arr[i-1]))
            rs++;
        else if (arr[i]=='B' && (i==0 || arr[i]==arr[i-1]))
            bs++;
        else
            break;
    }
    for (int i=n-1; i>=0; i--)
    {
        if (arr[i]=='R' && (i==n-1 || arr[i]==arr[i+1]))
            rl++;
        else if (arr[i]=='B' && (i==n-1 || arr[i]==arr[i+1]))
            bl++;
        else
            break;
    }
    
    cout<<min(r-rs, min(b-bs, min(r-rl, b-bl)));

    return 0;
}
