/*
접근) 아이디어를 떠올리기 위해 일단 문제를 단순화했습니다.
원형이 아닌 2*x 테이블이라고 생각하고 알고리즘을 짠 후, 원형으로 만나는 부분을 따로 처리하자는 생각이었습니다.

각각의 객석에 대해 DP를 짜기에는 시간&공간적 한계가 있어서, 각 열(두 칸)에 대한 DP를 짰습니다.
DP 테이블을 짤 때는, 철저하게 그 다음 열에서 그 열을 바라보는 관점으로 짜야 합니다. 다음 열에게 필요한 현재 열의 정보는, 자신과 가로로 이을 수 있는가 여부입니다.
위아래 두 칸에 각각 2가지 경우의 수(있음, 없음)가 있으므로 총 4개의 경우의 수가 나옵니다.

이렇게 2*x 직사각형 테이블이라고 생각하고 알고리즘을 짜면, 1번째 열과 n번째 열이 이어지는 경우를 고려하지 못합니다.
이 문제는 다음 방법으로 해결했습니다.
i번째 열이 i-1번째 열과 가로로 이어질 수 있는 것처럼, 1번째 열도 0번째 열과 가로로 이어질 수 있도록 했습니다.
1번째 열과 0번째 열의 이어짐은 1번째 열과 n번째 열의 이어짐을 의미합니다.
0번째 열의 대원 수를 99999로 설정하면, 1번째 열-n번째 열은 이어질 수 없지만, n-1번째 열-n번째 열은 이어질 수 있습니다.
반대로 0번째 열의 대원 수를 n번째 열의 대원 수로, n번째 열의 대원 수를 99999로 설정하면, 1번째 열-n번째 열은 이어질 수 있지만, n-1번째 열-n번째 열은 이어질 수 없습니다.
이 방법으로 위로는 n-1과 n, 아래로는 1과 n이 이어지는 등의 경우도 만들 수 있습니다.
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[10010][4];
int enemy[10010][2];

void SetDP(int n, int w) {
    for (int i=1; i<=n; i++) {
        int before_max = min(min(dp[i-1][0], dp[i-1][1]), min(dp[i-1][2], dp[i-1][3]));
        for (int j=0; j<4; j++)
            dp[i][j] = before_max+2;

        if (enemy[i][0]+enemy[i-1][0]<=w) {
            before_max = min(dp[i-1][2], dp[i-1][0]);
            dp[i][1] = min(dp[i][1], before_max+1);
        }
        if (enemy[i][1]+enemy[i-1][1]<=w) {
            before_max = min(dp[i-1][1], dp[i-1][0]);
            dp[i][2] = min(dp[i][2], before_max+1);
        }
        if (enemy[i][0]+enemy[i][1]<=w) {
            before_max = min(min(dp[i-1][0], dp[i-1][1]), min(dp[i-1][2], dp[i-1][3]));
            dp[i][3] = min(dp[i][3], before_max+1);
        }
        if (enemy[i][0]+enemy[i-1][0]<=w && enemy[i][1]+enemy[i-1][1]<=w) {
            before_max = dp[i-1][0];
            dp[i][3] = min(dp[i][3], before_max);
        }
    }
}

int main() {
    int t;

    cin>>t;
    for (int i=0; i<t; i++) {
        int n, w, ans;
        cin>>n>>w;

        
        memset(enemy, 0, sizeof(enemy));
        for (int j=0; j<2; j++) {
            for (int k=1; k<=n; k++)
                cin>>enemy[k][j];
        }

        if (n==1) {
            if (enemy[1][0]+enemy[1][1]<=w)
                cout<<"1\n";
            else
                cout<<"2\n";
            continue;
        }

        enemy[0][0] = 99999;
        enemy[0][1] = 99999;
        memset(dp, 0, sizeof(dp));
        SetDP(n, w);
        ans = min(min(dp[n][0], dp[n][1]), min(dp[n][2], dp[n][3]));

        swap(enemy[0][0], enemy[n][0]);
        swap(enemy[0][1], enemy[n][1]);
        memset(dp, 0, sizeof(dp));
        SetDP(n, w);
        ans = min(ans, min(min(dp[n][0], dp[n][1]), min(dp[n][2], dp[n][3])));

        swap(enemy[0][0], enemy[n][0]);
        memset(dp, 0, sizeof(dp));
        SetDP(n, w);
        ans = min(ans, min(min(dp[n][0], dp[n][1]), min(dp[n][2], dp[n][3])));

        swap(enemy[0][0], enemy[n][0]);
        swap(enemy[0][1], enemy[n][1]);
        memset(dp, 0, sizeof(dp));
        SetDP(n, w);
        ans = min(ans, min(min(dp[n][0], dp[n][1]), min(dp[n][2], dp[n][3])));

        cout<<ans<<'\n';
    }
    
    return 0;
}
