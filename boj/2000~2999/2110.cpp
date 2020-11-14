//parametric search를 이용하여 답을 찾습니다.
#include <iostream>
#include <algorithm>

using namespace std;

int house[200000];

bool Can(int n, int c, int len)  //len의 간격으로 설치할수 있는지 없는지 확인
{
    int cnt = 1, length = 0;

    for(int i=1; i<n; i++)
    {
        length += house[i]-house[i-1];
        if(length>=len)
        {
            cnt++;
            length = 0;
        }
        if(cnt>=c)
            return true;
    }
    return false;
}

int Parametric(int n, int c, int maxh)
{
    int mid, start = 1, last = maxh;
    int result = 0;

    while (start<=last)
    {
        mid = (start+last)/2;
        if(Can(n, c, mid))
        {
            start = mid+1;
            result = mid;
        }
        else
            last = mid-1;
    }
    return result;
}

int main()
{
    int n, c, maxh = 0;

    cin>>n>>c;
    for(int i=0; i<n; i++)
    {
        cin>>house[i];
        maxh = max(maxh, house[i]);
    }

    sort(house, house+n);

    cout<<Parametric(n, c, maxh);

    return 0;
}
