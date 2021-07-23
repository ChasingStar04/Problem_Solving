//학생1부터 순서대로 1, 2, 3, 4, ... 이렇게 주고
//순서쌍 (A, B)가 들어오면 학생A를 +1, 학생B를 -1 합니다.
#include <iostream>

using namespace std;

int arr[100010];
bool check[100010];

int main()
{
    int n, m;
    bool collect = true;

    cin>>n>>m;
    for (int i=1; i<=n; i++)
        arr[i] = i;
    for (int i=0; i<m; i++)
    {
        int big, small;
        cin>>big>>small;
        arr[big]++;
        arr[small]--;
    }
    
    for (int i=1; i<=n; i++)
    {
        if (check[arr[i]])
        {
            collect = false;
            break;
        }
        check[arr[i]] = true;
    }

    if (collect)
    {
        for (int i=1; i<=n; i++)
            cout<<arr[i]<<' ';
    }
    else
        cout<<-1;
    
    return 0;
}
