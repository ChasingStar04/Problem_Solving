/*
b[k]가 어떤 숫자인지는 바로 알 수 없지만, 어떤 숫자가 배열b에서 어디에 위치하는지는 알 수 있습니다.
ex) 4의 인덱스: 4/1 + 4/2 + 4/3 + 4/4 = 8 -> b[x] ~ b[8]까지 4
이를 이용하여, parametric search로 k번째 인덱스에 위치하는 숫자를 구합니다.
*/
#include <iostream>
#include <cmath>

using namespace std;

int Index(int n, int num)  //mid의 인덱스를 구하는 함수
{
    int cnt = 0;
    for(int i=1; i<=n; i++)
        cnt += min(n, num/i);
    return cnt;
}

int Parametric(int n, int k)
{
    int first = 1, last = k;
    int ans = 0;

    while (first<=last)
    {
        int mid = (first+last)/2;

        if(Index(n, mid)>=k)
        {
            ans = mid;
            last = mid-1;
        }
        else
            first = mid+1;    
    }
    return ans;
}

int main()
{
    int n, k;

    cin>>n>>k;

    cout<<Parametric(n, k);

    return 0;
}
