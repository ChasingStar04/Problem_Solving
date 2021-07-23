//전체 경기수 = (n*m*(m-1)*k/2 + n*m*(n-1)*m/2)*b 이므로
//d를 (n*m*(m-1)*k/2 + n*m*(n-1)*m/2)로 나누면 조건에 맞는 가장 큰 b를 구할 수 있습니다.
//구한 b*(n*m*(m-1)*k/2 + n*m*(n-1)*m/2)가 답이 되고, (n*m*(m-1)*k/2 + n*m*(n-1)*m/2)가 d보다 크다면 조건에 맞는 b가 존재하지 않으므로 -1을 출력합니다.
#include <iostream>

using namespace std;

int main()
{
    int t;

    cin>>t;
    for (int i=0; i<t; i++)
    {
        int n, m, k, d;
        int game = 0;
        cin>>n>>m>>k>>d;

        game += n*m*(m-1)*k/2; //같은지역리그
        game += n*m*(n-1)*m/2; //다른지역리그
        
        if (game>d)
            cout<<"-1\n";
        else
            cout<<(d/game)*game<<'\n';
    }

    return 0;
}
