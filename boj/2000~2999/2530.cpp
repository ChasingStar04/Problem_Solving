#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    int h, m, s;

    cin>>a>>b>>c;
    cin>>d;

    s = c+d;
    m = (s/60+b);
    h = (m/60+a)%24;
    s %= 60;
    m %= 60;

    cout<<h<<' '<<m<<' '<<s;

    return 0;
}
