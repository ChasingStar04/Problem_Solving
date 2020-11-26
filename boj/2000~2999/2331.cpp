//https://chasingstar.tistory.com/19
#include <iostream>
#include <cmath>

using namespace std;

//각 자리의 숫자를 p번 곱한 수들의 합
int Func(int num, int p)
{
    int result = 0;
    while (num)
    {
        result += pow((num%10), p);
        num /= 10;
    }
    return result;
}

int main()
{
    int a, p, visit[300000] = {0};
    int num, cnt = 1;

    cin>>a>>p;
    
    visit[a] = cnt++;
    num = Func(a, p);
    while (visit[num]==0)
    {
        visit[num] = cnt++;
        num = Func(num, p);
    }
    
    cout<<visit[num]-1;

    return 0;
}
