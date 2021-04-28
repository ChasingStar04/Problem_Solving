//배열을 나열하는 경우의 수는 최대 8!이므로 모든 경우를 탐색할 수 있습니다.
//재귀함수를 이용하여 가능한 모든 경우를 계산하여 최댓값을 출력합니다.
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int arr[10]; //원래 배열
int idx[10];
bool check[10];
int n;

int Func(int m)
{
    if (m==0)
    {
        int result = 0;
        for (int i=0; i<n-1; i++)
            result += abs(arr[idx[i]]-arr[idx[i+1]]);
        return result;
    }

    int result = 0;
    for (int i=0; i<n; i++)
    {
        if (!check[i])
        {
            idx[m-1] = i;
            check[i] = true;
            result = max(result, Func(m-1));
            check[i] = false;
        }
    }
    return result;
}

int main()
{
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>arr[i];
    
    cout<<Func(n);

    return 0;
}
