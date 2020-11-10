//문제 조건에 맞게 정렬하는 병합 정렬을 구현해서 풀었습니다22.
#include <iostream>

using namespace std;

struct xy
{
    int x;
    int y;
}  loca[100000];

bool cmp(xy a, xy b)  //왼쪽이 더 작다면 true
{
    if(a.y!=b.y)
        return a.y<b.y;
    else
        return a.x<b.x;
}

void Merge(int left, int right)  //병합정렬 병합부분
{
    static xy sorted[100000] = {0};
    int mid = (left+right)/2;
    int lptr = left, rptr = mid+1, sptr = left;

    while (lptr<=mid && rptr<=right)
    {
        if(cmp(loca[lptr], loca[rptr]))
            sorted[sptr++] = loca[lptr++];
        else
            sorted[sptr++] = loca[rptr++];
    }
    
    if(lptr>mid)  //왼쪽이 다 옮겨졌다면
    {
        while (rptr<=right)
            sorted[sptr++] = loca[rptr++];
    }
    else  //오른쪽이 다 옮겨졌다면
    {
        while (lptr<=mid)
            sorted[sptr++] = loca[lptr++];
    }

    for(int i=left; i<=right; i++)
        loca[i] = sorted[i];
    
    return;
}

void MergeSort(int left, int right)  //병합정렬
{
    if(left>=right)
        return;
    
    int mid = (left+right)/2;
    MergeSort(left, mid);
    MergeSort(mid+1, right);
    Merge(left, right);
    return;
}

int main()
{
    int n;

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>loca[i].x>>loca[i].y;
    
    MergeSort(0, n-1);
    for(int i=0; i<n; i++)
        cout<<loca[i].x<<' '<<loca[i].y<<'\n';
    
    return 0;
}
