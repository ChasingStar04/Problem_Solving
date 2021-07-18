//점을 색깔별로 나누어 저장한 후, 각각을 정렬합니다. 그 후 각 점에서 가장 가까운 같은 색깔의 점과의 거리를 구합니다.
//정렬된 상태이므로 양 옆 점 중 거리가 짧은 점을 고르면 됩니다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> spot[5010];

int main()
{
    int n;
    int cnt = 0;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        int x, y;
        cin>>x>>y;
        spot[y].push_back(x);
    }

    for (int i=1; i<=n; i++)
    {
        sort(spot[i].begin(), spot[i].end());
        for (int j=0; j<spot[i].size(); j++)
        {
            if (j==0)
                cnt += spot[i][j+1]-spot[i][j];
            else if (j==spot[i].size()-1)
                cnt += spot[i][j]-spot[i][j-1];
            else
                cnt += min(spot[i][j+1]-spot[i][j], spot[i][j]-spot[i][j-1]);
        }
    }

    cout<<cnt;

    return 0;
}
