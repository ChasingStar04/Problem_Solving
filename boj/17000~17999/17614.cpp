//n<=1000000 이므로 1부터 n까지 하나하나 3, 6, 9가 몇 개 있는지 계산하는 단순한 방법으로 풀 수 있습니다.
//어떤 수 A에 3, 6, 9가 몇 개 있는지 확인할때는 A%10 연산으로 마지막 자리 숫자를 확인한 후 A /= 10 연산으로 마지막 자리를 없애주고,
//또 A%10 연산으로 그 다음 자리를 확인하는 과정을 A=0 이 될 때까지 반복합니다.
#include <iostream>

using namespace std;

int main()
{
    int n;
    int result = 0;

    cin>>n;

    for (int i=1; i<=n; i++)
    {
        int num = i;
        while (num>0)
        {
            if (num%10==3 || num%10==6 || num%10==9)
                result++;
            num /= 10;
        }
    }
    cout<<result;

    return 0;
}
