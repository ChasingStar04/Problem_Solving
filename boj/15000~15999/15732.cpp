//규칙에 따라 도토리를 담았을 때, i번째 상자까지의 도토리 개수가 d개 이상이 되는 최소의 i를 이분 탐색으로 찾습니다.
#include <iostream>

using namespace std;

int n, k;
long long d;

struct Data
{
    int first;
    int last;
    int interval;
} rule[10010];

bool Above(int box) //box번째 상자까지의 도토리 개수가 d개 이상인가
{
    long long cnt = 0;

    for (int i=0; i<k; i++)
    {
        if (box>=rule[i].first)
            cnt += (min(box, rule[i].last)-rule[i].first)/rule[i].interval + 1;
    }
    return cnt>=d;
}

int main()
{
    cin>>n>>k>>d;

    for (int i=0; i<k; i++)
        cin>>rule[i].first>>rule[i].last>>rule[i].interval;
    
    int low = 0, high = 1000000;
    while (low<high)
    {
        int mid = (low+high)/2;
        if (Above(mid))
            high = mid;
        else
            low = mid+1;
    }
    cout<<high;

    return 0;
}
