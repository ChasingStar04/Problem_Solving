//0~999999까지의 숫자를 하나하나 탐색하여 그 숫자를 입력할 수 있는지 확인하고
//입력할 수 있다면 (n까지의 거리)+(숫자를 입력하는 데 사용한 버튼 수) 와 최솟값을 비교하여 최솟값을 갱신합니다.
//100은 시작점이라 숫자를 입력하는 데 사용한 버튼 수가 0이라는 점에 주의합니다.
#include <iostream>
#include <cstdlib>

using namespace std;

bool broken[10];

bool can_make(int num)
{
    do
    {
        if (broken[num%10])
            return false;
        num /= 10;
    }
    while (num);

    return true;
}

int length(int num)
{
    int ans = 0;
    do
    {
        num /= 10;
        ans++;
    }
    while (num);
    return ans;
}

int main()
{
    int n, m, ans = 1000000;

    cin>>n;
    cin>>m;
    for (int i=0; i<m; i++)
    {
        int tmp;
        cin>>tmp;
        broken[tmp] = true;
    }

    for (int i=0; i<1000000; i++)
    {
        if (i==100)
            ans = min(ans, abs(n-i));
        if (abs(n-i)+length(i)<ans && can_make(i))
            ans = abs(n-i)+length(i);
    }
    cout<<ans;

    return 0;
}
