//개수 테이블을 만듭니다. a(i)와 합쳐서 x가 되는 숫자의 개수를 찾는 건 O(1)로 해결.
#include <iostream>
#include <vector>

using namespace std;

int table[1000010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, cnt = 0;
    vector<int> a;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        int num;
        cin>>num;
        a.push_back(num);
    }
    cin>>x;

    for (int &i : a)
    {
        if (x-i<=1000000 && x-i>0)
            cnt += table[x-i];
        table[i]++;
    }
    cout<<cnt;

    return 0;
}
