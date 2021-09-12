/*
현재 강의실 중 종료 시간이 가장 이른 강의실보다 다음에 들어올 강의의 시작 시간이 더 빠르다면, 강의실을 추가해야 합니다.
아니라면, 종료 시간이 가장 이른 강의가 끝나고 그 강의실에서 다음 강의를 시작하면 됩니다.

이것을 우선순위 큐로 구현할 수 있습니다.
먼저, 강의들을 시작 시간이 빠른 순서대로 오름차순으로 정렬합니다.
가장 작은 값이 나오도록 pq를 만들고, 편의를 위해 pq에 종료 시간이 0인 강의를 넣어둡니다.
기본 강의실 개수는 1개로 합니다.

새 강의가 들어오면, 새 강의의 시작 시간과 pq의 맨 위의 값을 비교합니다.
(새 강의의 시작 시간) >= (pq의 맨 위의 값) 이라면, pq에서 값을 빼고 pq에 새 강의의 종료 시간을 넣어줍니다. <기존 강의실 이용>
(새 강의의 시작 시간) < (pq의 맨 위의 값) 이라면, 강의실 개수를 1 늘려주고 pq에 새 강의의 종료 시간을 넣어줍니다. <새 강의실 이용>
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
    int s;
    int t;
};

vector<Data> v;
priority_queue<int, vector<int>, greater<int>> pq;

bool cmp(Data a, Data b)
{
    if (a.s!=b.s)
        return a.s<b.s;
    else
        return a.t<b.t;
}

int main()
{
    int n;
    int ans = 1;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        int s, t;
        cin>>s>>t;
        v.push_back({s, t});
    }

    sort(v.begin(), v.end(), cmp);
    pq.push(0);
    for (Data &i : v)
    {
        int lately = pq.top();

        if (i.s>=lately)
        {
            pq.pop();
            pq.push(i.t);
        }
        else
        {
            ans++;
            pq.push(i.t);
        }
    }
    cout<<ans;

    return 0;
}
