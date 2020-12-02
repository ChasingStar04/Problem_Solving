/*
lis[n] = 길이가 n+1인 부분 수열을 만들 때, 끝 숫자의 최솟값

수 a가 lis.back()보다 더 크다면 push하고
아니라면 lis에서 a의 lower bound위치에 넣습니다.
*/
#include <iostream>
#include <vector>

using namespace std;

int arr[1000000];
vector<int> lis;

int lower_bound(int num)
{
    int first = 0, last = lis.size();

    while (first<last)
    {
        int mid = (first+last)/2;
        
        if(lis[mid]<num)
            first = mid+1;
        else
            last = mid;
    }
    return first;
}

int main()
{
    int n;

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    for(int i=0; i<n; i++)
    {
        if(lis.empty() || lis.back()<arr[i])
            lis.push_back(arr[i]);
        else
        {
            int idx = lower_bound(arr[i]);
            lis[idx] = arr[i];
        }
    }
    cout<<lis.size();

    return 0;
}