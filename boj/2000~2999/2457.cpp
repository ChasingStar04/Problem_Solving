/*
연결할 수 있는 구간 중 끝이 가장 긴 구간을 선택하는 것을 반복 -> 그리디

구간을 갱신할 때 s를 추가한 구간의 s가 아닌, 원래의 e로 함.
[0, 원래 e)까지는 이미 다른 구간이 커버하고 있던 부분이므로
새로운 구간이 단독으로 커버하는 구간은 [원래 e, 새로운 e)임.

새 구간의 e>원래 e일때,
새 구간의 s<=원래 s라면 s는 그대로 두고 e만 갱신.(원래 구간을 대체)
새 구간의 s>원래 s라면 e를 새구간의 e로, s는 위 문단처럼 갱신. (원래 구간 뒤에 추가)
*/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int MDtoDay(int m, int d)
{
    int ans = 0;
    for (int i=0; i<m-1; i++)
        ans += month[i];
    return ans+d;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first!=b.first) return a.first<b.first;
    else return a.second<b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<pair<int, int>> v;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        int m1, d1, m2, d2;

        cin>>m1>>d1>>m2>>d2;
        v.push_back({MDtoDay(m1, d1), MDtoDay(m2, d2)});
    }

    sort(v.begin(), v.end(), cmp);

    bool flag = false;
    int s = 0, e = MDtoDay(3, 1);
    int cnt = 0;
    for (pair<int, int> &p : v)
    {
        if (p.first>e)
            break;
        else if (e<p.second)
        {
            if (s>=p.first)
                e = p.second;
            else
            {
                s = e;
                e = p.second;
                cnt++;
            }
        }

        if (e>MDtoDay(11, 30))
        {
            cout<<cnt;
            flag = true;
            break;
        }
    }

    if (!flag)
        cout<<0;

    return 0;
}
