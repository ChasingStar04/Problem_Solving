/*
기본적인 아이디어는 +60, +10, -10, +1, -1 버튼을 순서대로 누르는 dfs입니다.

예를들어 n=95이고, 현재 +60버튼을 눌러야 한다면
+60버튼을 x번 눌러 갈 수 있는 0, 60, 120, 180, 240, ... 등등을 모두 탐색하지 않고
95랑 위아래로 제일 가까운 값인 60과 120만 탐색 합니다.
이렇게하면 최대 3^5번만 탐색을 하면 되기 때문에 시간 초과를 피할 수 있습니다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

struct Data
{
    int arr[5];
};

int arr[5] = {60, 10, -10, 1, -1};
int n;
int res[5];

bool CP(int a[])
{
    int suma = 0, sumr = 0;
    for (int i=0; i<5; i++)
    {
        suma += a[i];
        sumr += res[i];
    }
    if (suma!=sumr)
        return suma<sumr;
    
    for (int i=0; i<5; i++)
    {
        if (a[i]!=res[i])
            return a[i]<res[i];
    }
    return false;
}

void Func(int num, Data s, int idx)
{
    if (idx==5)
    {
        if (num==n && CP(s.arr))
            copy(s.arr, s.arr+5, res);
    }
    else
    {
        int a = (n-num)/arr[idx];
        if (a>=0 && num+arr[idx]*a>=0)
        {
            s.arr[idx] = a;
            Func(num+arr[idx]*a, s, idx+1);
        }
        if ((a+1)>=0 && num+arr[idx]*(a+1)>=0)
        {
            s.arr[idx] = a+1;
            Func(num+arr[idx]*(a+1), s, idx+1);
        }
        s.arr[idx] = 0;
        Func(num, s, idx+1);
    }
    return;
}

int main()
{
    int t;

    cin>>t;
    for (int i=0; i<t; i++)
    {
        cin>>n;
        memset(res, 0x0f, sizeof(res));
        Func(0, {0}, 0);
        for (int& j : res)
            cout<<j<<' ';
        cout<<'\n';
    }

    return 0;
}
