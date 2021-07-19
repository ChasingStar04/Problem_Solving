//삼중 반복문으로 모든 경우의 수를 확인합니다.
#include <iostream>

using namespace std;

int main()
{
    int a, b, c, n;

    cin>>a>>b>>c>>n;

    for (int i=0; i<=n; i+=a)
    {
        for (int j=i; j<=n; j+=b)
        {
            for (int k=j; k<=n; k+=c)
            {
                if (k==n)
                {
                    cout<<1;
                    return 0;
                }
            }
        }
    }

    cout<<0;

    return 0;
}
