//TLE -> 에디토리얼 보고 작성
/*
갈 수 있는 노드가 없는 노드를 제외하면, 모든 노드는 최대로 이동하기 위해 자신보다 큰 다른 노드를 지나가야 합니다.
즉, (최대이동횟수) = (자신이 갈 수 있는 노드의 최대이동횟수의 최댓값) + 1(그 노드까지 이동) 로 볼 수 있고
x좌표와 y좌표가 같은 노드로만 이동할 수 있으므로 (자신이 갈 수 있는 노드의 최대이동횟수의 최댓값)을 x좌표에서의 최댓값과 y좌표에서의 최댓값으로 정리하여
x좌표와 y좌표를 테이블로 하는 dp로 해결할 수 있습니다.

x좌표가 i인 노드가 최대로 이동할 수 있는 횟수를 xmax[i], y좌표가 i인 노드가 최대로 이동할 수 있는 횟수를 ymax[i]로 합니다.
a값이 큰 노드부터 자신의 최대이동횟수를 max(xmax[x좌표], ymax[y좌표]) 로 구하고 xmax와 ymax를 원래 값과 (자신의 최대이동횟수)+1 중 큰 값으로 갱신합니다.
a값이 같은 노드들끼리는 먼저 모든 a값의 같은 노드들의 최대이동횟수를 구하고 나서 갱신을 해야 합니다.
그렇지 않고 a값이 같은 노드들끼리 구함->갱신->구함->갱신 하게되면 a값이 같은 노드들 중 뒤의 노드가 a값이 같은 앞의 노드를 지나가는 경로를 탈 수 있습니다.
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int x[200010], y[200010], a[200010];
int xmax[200010], ymax[200010];
int result[200010];
map<int, vector<int>> mp;

int main()
{
    int h, w, n;
    cin>>h>>w>>n;
    for (int i=0; i<n; i++)
    {
        cin>>x[i]>>y[i]>>a[i];
        mp[a[i]].push_back(i);
    }

    for (auto i = mp.rbegin(); i!=mp.rend(); i++)
    {
        for (int &i : i->second) result[i] = max(xmax[x[i]], ymax[y[i]]);
        for (int &i : i->second)
        {
            xmax[x[i]] = max(xmax[x[i]], result[i]+1);
            ymax[y[i]] = max(ymax[y[i]], result[i]+1);
        }
    }
    
    for (int i=0; i<n; i++)
        cout<<result[i]<<'\n';
    
    return 0;
}
