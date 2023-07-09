//mod연산으로 끝에 한 자리씩 떼서
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    int cnt[10] = {0};

    cin>>a;
    cin>>b;
    cin>>c;
    d = a*b*c;

    while (d>0)
    {
        cnt[d%10]++;
        d /= 10; 
    }
    for (int i=0; i<10; i++)
        cout<<cnt[i]<<'\n';
    
    return 0;
}
