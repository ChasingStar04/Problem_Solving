/*
첫번째 배열+두번째 배열의 가능한 모든 합(이하 v1)과
세번째 배열+네번째 배열의 가능한 모든 합(이하 v2)을 미리 구한 후 정렬합니다.
v1의 값을 하나씩 뽑아 부호를 바꾼 값이 v2에 있는지 이진 탐색으로 확인하고, 그 개수만큼 더해줍니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v1, v2;

int main()
{
    int n;
    int input[4][4010] = {0};
    long long cnt = 0;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<4; j++)
            cin>>input[j][i];
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            v1.push_back(input[0][i]+input[1][j]);
    }
    sort(v1.begin(), v1.end());

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            v2.push_back(input[2][i]+input[3][j]);
    }
    sort(v2.begin(), v2.end());

    for (int& i : v1)
        cnt += upper_bound(v2.begin(), v2.end(), -i) - lower_bound(v2.begin(), v2.end(), -i);
    cout<<cnt;

    return 0;
}
