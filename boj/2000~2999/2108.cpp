/*
입력을 받으면서 최대/최소(범위)와 합(평균)을 구하였고
중앙값과 최빈값은 count 배열을 이용하여 구했습니다.
*/
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct mm
{
    int mid;
    int mode;
};

mm GetMM(int n, int arr[])
{
    int count[8001] = {0}, mode = 0;
    int modecnt = 0, cnt = 0;
    mm result = {-5555};

    for(int i=0; i<n; i++)
    {
        count[arr[i]+4000]++;
        if(count[arr[i]+4000]>mode)
            mode = count[arr[i]+4000];
    }
    
    for(int i=0; i<=8000; i++)
    {
        if(i==8000)
            int debug=0;
        cnt += count[i];
        if(cnt>=n/2+1 && result.mid==-5555)  //지금까지의 원소의 개수가 (n/2+1)을 처음 넘는 수 = 중간값
            result.mid = i-4000;
        if(count[i]==mode && modecnt<2)  //count[n]==mode인 첫번째 혹은 두번째 수 = 최빈값
        {
            result.mode = i-4000;
            modecnt++;
        }
    }

    return result;
}

int main()
{
    int n, mid = 0, mode = 0, maxnum = -555555, minnum = 555555;
    int arr[500000] = {0};
    long long sum = 0;

    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        sum += arr[i];
        maxnum = max(maxnum, arr[i]);
        minnum = min(minnum, arr[i]);
    }
    
    mm midmode = GetMM(n, arr);
    
    cout<<round((double)sum/n)<<'\n';
    cout<<midmode.mid<<'\n';
    cout<<midmode.mode<<'\n';
    cout<<maxnum-minnum<<'\n';

    return 0;
}
