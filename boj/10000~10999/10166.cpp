/*
(번째)/(반지름) 값을 약분해서
값이 중복되지 않는 경우에만 +1 합니다
*/
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int fountain[2000][2000];

int Gcd(int a, int b)
{
    if(b==0)
        return a;
    return Gcd(b, a%b);
}

int main()
{
    int d1, d2;
    int result = 0;

    cin>>d1>>d2;
    
    for(int i=d1; i<=d2; i++)
    {
        for(int j=1; j<=i; j++)
        {
            int gcd = Gcd(j, i);
            int a = j/gcd;
            int b = i/gcd;

            if(fountain[a][b]==0)
            {
                fountain[a][b] = 1;
                result++;
            }
        }
    }
    cout<<result;

    return 0;
}