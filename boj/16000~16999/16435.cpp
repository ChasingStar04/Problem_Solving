//과일을 오름차순으로 정렬해서 순서대로 먹을 수 있으면 길이를 1 늘리고, 먹을 수 없으면 break 합니다.
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, l;
    int berry[1010] = {0};

    cin>>n>>l;
    for (int i=0; i<n; i++)
        cin>>berry[i];
    
    sort(berry, berry+n);
    for (int i=0; i<n; i++)
    {
        if (l>=berry[i])
            l++;
        else
            break;
    }
    cout<<l;

    return 0;
}
