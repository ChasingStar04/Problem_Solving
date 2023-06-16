//n에 비해 물고기의 수 m이 심하게 작습니다. m을 기준으로 탐색을 하는 게 좋아보입니다.
#include <iostream>

using namespace std;

int main()
{
    int n, len, m;
    int fish[110][2] = {0};
    int dist[4][2] = {1, 1, 1, -1, -1, 1, -1, -1};
    int res = 0;

    cin>>n>>len>>m;
    for (int i=0; i<m; i++)
        cin>>fish[i][0]>>fish[i][1];
    
    for (int i=0; i<m; i++)
    {
        for (int j=1; j<len/2; j++)
        {
            int x_size = j, y_size = (len/2)-j;
            for (int k=0; k<=x_size; k++)
            {

                int xs = fish[i][0]-k;
                int xe = fish[i][0]+x_size-k;
                int ys = fish[i][1];
                int ye = fish[i][1]+y_size;

                int cnt = 0;
                for (int l=0; l<m; l++)
                    if (fish[l][0]>=xs && fish[l][0]<=xe && fish[l][1]>=ys && fish[l][1]<=ye)
                        cnt++;
                res = max(res, cnt);
            }
        }
    }

    cout<<res;

    return 0;
}
