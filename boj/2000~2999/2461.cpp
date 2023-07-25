/*
접근) 임의의 학생을 최소값으로 할 때, 만들 수 있는 최소의 차를 구합니다. pq를 이용하면, O(log n)에 구할 수 있습니다.
이걸 모든 학생에 대해 구합니다.
O(n*m*log n)

구현) 전체 학생들을 담은 벡터와 반별 학생들을 담은 벡터를 만들어 각각 정렬.
반별로 가장 작은 학생을 pq에 넣음.
현재 학생을 최소값으로 할 때 차이의 차 = (pq에 있는 학생 중 최댓값) - 현재 학생 값
이후 반에서 현재 학생 다음 학생을 pq에 넣고, 전체에서 현재 학생 다음 학생으로 넘어가 위 과정을 반복.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first!=b.first) return a.first<b.first;
    else return a.second<b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, ans = 0x3f3f3f3f;
    vector<pair<int, int>> v;
    vector<int> vc[1010];

    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            int num;
            cin>>num;
            v.push_back({num, i});
            vc[i].push_back(num);
        }
    }

    sort(v.begin(), v.end(), cmp);
    for (int i=0; i<n; i++)
        sort(vc[i].begin(), vc[i].end(), greater<int>());
    
    priority_queue<int> pq;
    for (int i=0; i<n; i++)
        pq.push(vc[i].back());
    
    int max_d;
    for (pair<int, int> &p : v)
    {
        max_d = pq.top()-p.first;
        ans = min(ans, max_d);

        vc[p.second].pop_back();
        if (vc[p.second].empty())
            break;
        else
            pq.push(vc[p.second].back());
    }
    cout<<ans;

    return 0;
}
