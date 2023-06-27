/*
공통부분을 구한 후, 공통부분의 크기로 abcd를 판단합니다.
공통부분을 만드는 변은 원 직사각형들의 변의 조합이고, 직사각형을 표현하는 네 개의 숫자를 각 변으로 해석하면 해결법이 보입니다.
*/
#include <iostream>

using namespace std;

int main()
{
    for (int i=0; i<4; i++)
    {
        int xs1, ys1, xe1, ye1;
        int xs2, ys2, xe2, ye2;
        int over_xs, over_ys, over_xe, over_ye;

        cin>>xs1>>ys1>>xe1>>ye1;
        cin>>xs2>>ys2>>xe2>>ye2;

        over_xs = max(xs1, xs2);
        over_ys = max(ys1, ys2);
        over_xe = min(xe1, xe2);
        over_ye = min(ye1, ye2);

        if (over_xe-over_xs>0 && over_ye-over_ys>0)
            cout<<"a\n";
        else if (over_xe-over_xs<0 || over_ye-over_ys<0)
            cout<<"d\n";
        else if (over_xe-over_xs>0 || over_ye-over_ys>0)
            cout<<"b\n";
        else
            cout<<"c\n";
    }

    return 0;
}
