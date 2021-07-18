//풀이 보고 풀었습니다.
//https://m.blog.naver.com/martinok1103/222094801892 설명 잘돼있으니까 이 글 참고하세요.
//입력에서 X(i)<X(i+1)이라는 말이 없으므로 정렬을 해줘야합니다.
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000010];
int dist[2000010];

int main()
{
    int n, r, m;
    int sum = 0, ms = 0;

    cin>>n;
    cin>>r>>m;
    for (int i=0; i<n; i++)
        cin>>arr[i];
    sort(arr, arr+n);

    for (int i=0; i<n-1; i++)
        dist[i] = arr[i+1]-arr[i]-(2*r);
    dist[n-1] = m-(arr[n-1]-arr[0])-(2*r);
    for (int i=0; i<n-1; i++)
        dist[i+n] = arr[i+1]-arr[i]-(2*r);
    
    for (int i=0; i<2*n-1; i++)
    {
        sum += dist[i];
        if (sum<0) sum=0;
        ms = max(ms, sum);
    }

    cout<<(ms+1)/2;

    return 0;
}
