//2013년 = F9가 중요한 정보였다.
#include <iostream>

using namespace std;

int main()
{
    int n;
    char ez = 'A';
    int gan = 0;
    
    cin>>n;
    n += 56;
    gan += n%10;
    ez += n%12;
    cout<<ez<<gan;
    
    return 0;
}
