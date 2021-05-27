//소수들을 구해 벡터에 저장한 후, 투 포인터를 이용합니다.
#include <iostream>
#include <vector>

using namespace std;

bool not_prime[4000010];
vector<int> prime;

void GetPrime(int n)
{
    for (int i=2; i<=n; i++)
    {
        if (not_prime[i]) continue;
        prime.push_back(i);
        for (int j=2; i*j<=n; j++)
            not_prime[i*j] = true;
    }
    return;
}

int TwoPointer(int n)
{
    int s = 0, e = 0;
    int sum = 0, cnt = 0;

    while (true)
    {
        if (sum>=n)
            sum -= prime[s++];
        else if (e==prime.size())
            break;
        else
            sum += prime[e++];
        if (sum==n)
            cnt++;
    }

    return cnt;
}

int main()
{
    int n;

    cin>>n;
    GetPrime(n);
    cout<<TwoPointer(n);

    return 0;
}
