//c++로 병합 정렬을 구현해봅시다.
#include <iostream>

using namespace std;

int sorted[1000000], list[1000000];

void Merge(int left, int right, int list[])
{
    int mid = (left+right)/2;
    int lptr = left, rptr = mid+1, sptr = left;

    while (lptr<=mid && rptr<=right)
    {
        if(list[lptr]<=list[rptr])
            sorted[sptr++] = list[lptr++];
        else
            sorted[sptr++] = list[rptr++];
    }

    if(lptr>mid)
    {
        while (rptr<=right)
            sorted[sptr++] = list[rptr++];
    }
    else
    {
        while (lptr<=mid)
            sorted[sptr++] = list[lptr++];
    }

    for(int i=left; i<=right; i++)
        list[i] = sorted[i];

    return;
}

void MergeSort(int left, int right, int list[])
{
    if(left>=right)
        return;
    
    int mid = (left+right)/2;
    MergeSort(left, mid, list);
    MergeSort(mid+1, right, list);
    Merge(left, right, list);
    return;    
}

int main()
{
    int n;

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>list[i];
    
    MergeSort(0, n-1, list);
    for(int i=0; i<n; i++)
        cout<<list[i]<<'\n';
    
    return 0;
}
