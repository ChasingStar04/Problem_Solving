//시계는 멈출 줄 모르고
#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    int h, m;

    cin>>a>>b;
    cin>>c;

    m = b+c;
    h = (m/60+a)%24;
    m %= 60;

    cout<<h<<' '<<m;

    return 0;
}
