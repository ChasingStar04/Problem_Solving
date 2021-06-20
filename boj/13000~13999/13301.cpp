//각각의 정사각형의 크기는 피보나치 수열입니다.
//따라서 n번째 정사각형의 크기를 f(n)이라 할때, 총 직사각형의 둘레는 f(n)*4 + f(n-1)*2 입니다.
//f(n)*4 + f(n-1)*2 = f(n+1)*2 + f(n)*2 = f(n+2)*2 로도 나타낼 수 있습니다.
#include <iostream>

using namespace std;

int main()
{
    long long arr[82] = {0};
    int n;

    cin>>n;
    arr[1] = 1;
    for (int i=2; i<=n; i++)
        arr[i] = arr[i-1]+arr[i-2];
    
    cout<<arr[n]*4+arr[n-1]*2;

    return 0;
}
