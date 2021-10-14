//임의의 maxhp로 던전을 클리어할 수 있는지 O(n)에 계산할 수 있으므로 이진 탐색을 통하여 O(n log n)으로 최소의 maxhp를 계산할 수 있습니다.
#include <iostream>
#include <cmath>

using namespace std;

int n, ha;
struct Data
{
    int t;
    int a;
    int hp;
} room[123460];

bool CanClear(long long maxhp)
{
    long long hp = maxhp, atk = ha;

    for (int i=0; i<n; i++)
    {
        if (room[i].t==1)
        {
            long long hero = (hp%room[i].a==0) ? hp/room[i].a : hp/room[i].a+1;
            long long monster = (room[i].hp%atk==0) ? room[i].hp/atk : room[i].hp/atk+1; //각각 몇대 맞아야 죽는가
            if (hero>=monster)
                hp -= (monster-1)*room[i].a;
            else
                return false;
        }
        else if (room[i].t==2)
        {
            hp = min(hp+room[i].hp, maxhp);
            atk += room[i].a;
        }
    }

    return true;
}

int main()
{
    cin>>n>>ha;
    
    for (int i=0; i<n; i++)
    {
        int t, a, hp;
        cin>>room[i].t>>room[i].a>>room[i].hp;
    }

    long long low = 0, high = 1000000000000000000;
    while (low<high)
    {
        long long mid = (low+high)/2;
        if (CanClear(mid))
            high = mid;
        else
            low = mid+1;
    }
    
    cout<<high;

    return 0;
}
