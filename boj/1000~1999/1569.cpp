/*
마음에 들 만큼 효율적인 알고리즘을 생각해내지 못해서, 무식한 방법으로 풀었습니다.

1. 가장자리를 잡습니다
정사각형 바깥에 점이 있으면 안 되므로
정사각형의 동서남북 각 변은 각 방면으로 가장 먼 점의 값보다는 커야 합니다.
그렇게 각 방면으로 가장 먼 점의 값을 maxx, minx, maxy, miny로 잡습니다.

2. maxx-minx = maxy-miny 일 경우
정사각형이 특정됩니다.
정사각형의 변이 아니라 안에 있을 경우만 확인하면 됩니다.

3. maxx-minx != maxy-miny 일 경우
둘 중 더 큰 값이 정사각형의 변의 길이가 됩니다.
가로가 더 길다면 세로변 두 개가, 세로가 더 길다면 가로변 두 개가 특정됩니다.
특정되는 변에 있지 않은 경우에 집중합니다.
*/
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    int dot[51][2] = {0};
    int maxx = -2000, minx = 2000, maxy = -2000, miny = 2000; //점들 중 x, y의 최대, 최소
    int distx, disty, square; // square = 정사각형의 변 길이이자 출력값

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>dot[i][0]>>dot[i][1];
        maxx = max(maxx, dot[i][0]);
        minx = min(minx, dot[i][0]);
        maxy = max(maxy, dot[i][1]);
        miny = min(miny, dot[i][1]);
    }

    distx = maxx-minx;
    disty = maxy-miny;
    square = max(distx, disty);

    if (distx==disty) {
        for (int i=0; i<n; i++) {
            if (dot[i][0]>minx && dot[i][0]<maxx && dot[i][1]>miny && dot[i][1]<maxy) {
                square = -1;
                break;
            }
        }
    }
    else if (distx<disty) {
        int x1 = 2000, x2 = 2000;
        for (int i=0; i<n; i++) {
            if (dot[i][1]>miny && dot[i][1]<maxy && x1!=dot[i][0] && x2!=dot[i][0]) {
                if (x1==2000) x1 = dot[i][0];
                else if (x2==2000) x2 = dot[i][0];
                else {
                    square = -1;
                    break;
                }
            }
        }
        if (x1!=2000 && x2!=2000 && abs(x1-x2)!=square)
            square = -1;
    }
    else {
        int y1 = 2000, y2 = 2000;
        for (int i=0; i<n; i++) {
            if (dot[i][0]>minx && dot[i][0]<maxx && y1!=dot[i][1] && y2!=dot[i][1]) {
                if (y1==2000) y1 = dot[i][1];
                else if (y2==2000) y2 = dot[i][1];
                else {
                    square = -1;
                    break;
                }
            }
        }
        if (y1!=2000 && y2!=2000 && abs(y1-y2)!=square)
            square = -1;
    }
    cout<<square;

    return 0;
}
