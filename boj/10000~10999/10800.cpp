/*
풀이 1. O(n) 풀이
공을 크기가 작은 순서대로 처리합니다.
각각의 공마다 현재 저장된 (모든 공의 크기 합)에서 (같은 색 공의 크기 합)을 빼 사로잡을 수 있는 공의 크기 합을 구합니다.
그 후 (모든 공의 크기 합)과 (같은 색 공의 크기 합)을 갱신합니다.
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Data
{
    int color;
    int num;
};

map<int, vector<Data>> entire;
int partial_sum[200010];
int result[200010];

int main()
{
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        int color, size;
        cin>>color>>size;
        entire[size].push_back({color, i});
    }

    int sum = 0;
    for (auto &i : entire)
    {
        for (Data &j : i.second)
            result[j.num] = sum-partial_sum[j.color];
        for (Data &j : i.second)
        {
            sum += i.first;
            partial_sum[j.color] += i.first;
        }
    }

    for (int i=0; i<n; i++)
        cout<<result[i]<<'\n';
    
    return 0;
}

/*
풀이 2. O(n log n) 풀이. 원래 풀이
(사로잡을 수 있는 공의 크기 합) = (자신보다 크기가 작은 모든 공의 크기 합) - (자신보다 크기가 작은 같은 색깔 공의 크기 합) 입니다.
전체 공을 오름차순으로 정렬한 배열과 첫번째 공부터 자신까지의 크기의 합을 저장하는 만들고,
각의 색깔별로 오름차순으로 정렬한 배열과 첫번째 공부터 자신까지의 크기의 합을 저장하는 배열을 만듭니다.
그 후 첫번째 공부터 전체 공 배열에서의 위치와 색깔별 공 배열에서의 위치를 lower_bound를 이용하여 찾습니다.
찾은 위치를 이용하여 (자신보다 크기가 작은 모든 공의 크기 합) - (자신보다 크기가 작은 같은 색깔 공의 크기 합) 을 구합니다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
    int color;
    int size;
} ball[200010];
vector<int> entire_ballsize, entire_ballsize_sum;
vector<int> ballsize[200010], ballsize_sum[200010];

int main()
{
    int n;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>ball[i].color>>ball[i].size;
        entire_ballsize.push_back(ball[i].size);
        ballsize[ball[i].color].push_back(ball[i].size);
    }

    sort(entire_ballsize.begin(), entire_ballsize.end());
    for (int i=1; i<=n; i++)
    {
        if (!ballsize[i].empty())
            sort(ballsize[i].begin(), ballsize[i].end());
    }

    for (int i=0; i<entire_ballsize.size(); i++)
    {
        if (entire_ballsize_sum.empty())
            entire_ballsize_sum.push_back(entire_ballsize[i]);
        else
            entire_ballsize_sum.push_back(entire_ballsize_sum.back()+entire_ballsize[i]);
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<ballsize[i].size(); j++)
        {
            if (ballsize_sum[i].empty())
                ballsize_sum[i].push_back(ballsize[i][j]);
            else
                ballsize_sum[i].push_back(ballsize_sum[i].back()+ballsize[i][j]);
        }
    }
    
    for (int i=0; i<n; i++)
    {
        int entire = lower_bound(entire_ballsize.begin(), entire_ballsize.end(), ball[i].size)-entire_ballsize.begin();
        int mycolor = lower_bound(ballsize[ball[i].color].begin(), ballsize[ball[i].color].end(), ball[i].size)-ballsize[ball[i].color].begin();
        cout<<(entire!=0 ? entire_ballsize_sum[entire-1] : 0) - (mycolor!=0 ? ballsize_sum[ball[i].color][mycolor-1] : 0)<<'\n';
    }

    return 0;
}
*/
