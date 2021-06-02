/*
풀이 1
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

void Solve(string s)
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

    Solve(s.substr(1, s.length()-1));
}

void DeleteZero(string s)
{
    int d = 1;
    for (int i=0; i<s.length(); i++)
    {
        arr[0] -= d*(s.length()-i);
        d *= (d==1 ? 9 : 10);
    }
}

int main()
{
    string s;

    cin>>s;
    Solve(s);
    DeleteZero(s);
    for (long long& i : arr)
        cout<<i<<' ';
    
    return 0;
}

/*
풀이 2. 인터넷에서 많이 보이는 풀이법입니다.
a~b까지 마지막 자리에 있는 숫자의 갯수를 구할 때
a의 마지막 자리수를 0으로, b의 마지막 자리수를 9로 맞춰주면 편하게 구할 수 있습니다.
이렇게 마지막 자리부터 한 자리씩 구합니다.
*/
/*
#include <iostream>

using namespace std;

long long arr[10];

void Calc(long long n, int ten)
{
    while (n>0)
    {
        arr[n%10] += ten;
        n /= 10;
    }
}

void Solve(long long s, long long e, int ten)
{
    while (s%10!=0 && s<=e)
    {
        Calc(s, ten);
        s++;
    }

    if (s>e) return;

    while (e%10!=9 && e>=s)
    {
        Calc(e, ten);
        e--;
    }

    long long cnt = e/10 - s/10 + 1;
    for (int i=0; i<10; i++)
        arr[i] += cnt*ten;
    
    Solve(s/10, e/10, ten*10);
}

int main()
{
    long long n;

    cin>>n;
    Solve(1, n, 1);
    for (int i=0; i<10; i++)
        cout<<arr[i]<<' ';
    
    return 0;
}
*/