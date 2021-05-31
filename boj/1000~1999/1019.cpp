/*
예를들어 F(234567)을 구한다고 하면
제일 큰 자릿수에 들어가는 숫자의 개수 + 0~199999에 들어가는 숫자의 개수 + F(34567)로 구할 수 있습니다.
이렇게하면 000012, 012345 같은 앞쪽에 들어가면 안되는 0까지 같이 세게 되는데
들어가면 안되는 0들은 DeleteZero 함수에서 제거합니다.
*/
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

long long arr[10];

void Func(string s)
{
    if (s.length()==0)
        return;
    
    long long a = s.length()>1 ? pow(10, s.length()-2) : 0;
    for (int i=0; i<10; i++)
        arr[i] += (s[0]-'0')*a*(s.length()-1);
    
    for (int i=0; i<=s[0]-'0'; i++)
    {
        if (i==s[0]-'0')
            arr[i] += (long long)(s.length()>1 ? stoi(s.substr(1, s.length()-1))+1 : 1);
        else
            arr[i] += (long long)pow(10, s.length()-1);
    }

    Func(s.substr(1, s.length()-1));
    return;
}

void DeleteZero(string s)
{
    int d = 1;
    for (int i=0; i<s.length(); i++)
    {
        arr[0] -= d*(s.length()-i);
        d *= (d==1 ? 9 : 10);
    }
    return;
}

int main()
{
    string s;

    cin>>s;
    Func(s);
    DeleteZero(s);
    for (long long& i : arr)
        cout<<i<<' ';
    
    return 0;
}
