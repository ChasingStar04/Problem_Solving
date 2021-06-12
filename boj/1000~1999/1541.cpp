//첫 빼기가 들어오면, 이후의 숫자들은 모두 다음 빼기 전까지 괄호를 치는 방법으로 마이너스로 만들 수 있습니다.
//따라서 빼기가 들어오기 전 숫자들은 더해주고, 들어온 후 숫자들은 빼줍니다.

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    bool minus = false;
    int ans = 0, num = 0;

    cin>>input;
    for (char& i : input)
    {
        if (i>='0' && i<='9')
            num = num*10 + (i-'0');
        else
        {
            if (minus)
                ans -= num;
            else
                ans += num;
            num = 0;

            if (i=='-')
                minus = true;
        }
    }
    if (minus)
        ans -= num;
    else
        ans += num;
    
    cout<<ans;

    return 0;
}
