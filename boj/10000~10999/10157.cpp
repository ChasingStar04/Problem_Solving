//2차원 bool배열로 칸을 만들고 직접 채워보면서 위치를 찾습니다.
#include <iostream>

using namespace std;

int main() {
    int c, r, k;

    cin>>c>>r;
    cin>>k;

    if (k>c*r) cout<<0;
    else {
        int move[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
        bool maps[1010][1010] = {0};
        int nowx = 1, nowy = 1;
        int cnt = 1;
        int d = 0; //방향

        for (int i=0; i<=c+1; i++) maps[i][0] = true;
        for (int i=0; i<=c+1; i++) maps[i][r+1] = true;
        for (int i=0; i<=r+1; i++) maps[0][i] = true;
        for (int i=0; i<=r+1; i++) maps[c+1][i] = true;

        while (cnt<k) {
            maps[nowx][nowy] = true;
            int nextx = nowx+move[d][0];
            int nexty = nowy+move[d][1];

            if (maps[nextx][nexty]) {
                d = (d+1)%4;
            }
            else {
                nowx = nextx;
                nowy = nexty;
                cnt++;
            }
        }
        cout<<nowx<<' '<<nowy;
    }

    return 0;
}
