/*
2차원으로 복잡하게 운동하는 것 같아 보이지만,
독립적인 1차원 운동 2개를 하고 있을 뿐입니다.
*/
#include <iostream>

using namespace std;

int main()
{
    int w, h, p, q, t;

    cin>>w>>h;
    cin>>p>>q;
    cin>>t;

    int newp = p+t, newq = q+t;
    newp = (newp/w)%2==0 ? newp%w : w-(newp%w);
    newq = (newq/h)%2==0 ? newq%h : h-(newq%h);

    cout<<newp<<' '<<newq;
    
    return 0;
}
