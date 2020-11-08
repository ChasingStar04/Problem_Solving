/*
c++로 삽입 정렬을 구현해봅시다.
삽입 정렬은 손 안의 카드를 정렬하는 방법과 유사한 알고리즘입니다.
*/
#include <iostream>

using namespace std;

void Sort(int n, int arr[])
{
    for(int i=1; i<n; i++)
    {
        int num = arr[i];
        int j;
        for(j=i-1; j>=0; j--)
        {
            if(arr[j]>num)
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j+1] = num;
    }
    return;
}

int main()
{
    int n, arr[1000] = {0};

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    Sort(n, arr);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<'\n';
    
    return 0;
}
