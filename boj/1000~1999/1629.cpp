#include <iostream>

using namespace std;

long long Func(long long a, long long b, long long c)
{
    if (b==1) return a;
    else
    {
        long long d = Func(a, b/2, c);
        d = (d*d)%c;
        if (b%2==0) return d;
        else return (d*a)%c;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;
    
    cin>>a>>b>>c;
    cout<<Func(a%c, b, c);

    return 0;
}
