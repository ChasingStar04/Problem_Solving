//문제대로 구현합니다.
#include <iostream>

using namespace std;

int main()
{
    int a[10] = {0}, b[10] = {0};
    int awin = 0, bwin = 0;

    for (int i=0; i<10; i++)
        cin>>a[i];
    for (int i=0; i<10; i++)
        cin>>b[i];
    
    for (int i=0; i<10; i++)
    {
        if (a[i]>b[i]) awin++;
        else if (b[i]>a[i]) bwin++;
    }
    if (awin>bwin) cout<<'A';
    else if (bwin>awin) cout<<'B';
    else cout<<'D';

    return 0;
}
