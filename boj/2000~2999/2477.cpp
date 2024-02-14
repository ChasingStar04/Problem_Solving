//성질 파악. 큰 사각형의 변은 반시계방향으로 돌고, 작은 사각형의 변은 시계방향으로 돈다.
//방향으로 판단 후 (큰 사각형 넓이)-(작은 사각형 넓이)를 구한다.
#include <iostream>

using namespace std;

int ccw[5] = {0, 4, 3, 1, 2}; //CounterClockWise

int main()
{
    int k, d[6] = {0}, size[6] = {0};
    int big_square_size = 0, small_square_size = 0;
    
    cin>>k;
    for (int i=0; i<6; i++)
        cin>>d[i]>>size[i];
    for (int i=0; i<6; i++)
    {
        if (ccw[d[i]] == d[(i+1)%6])
            big_square_size = max(big_square_size, size[i]*size[(i+1)%6]);
        else
            small_square_size = size[i]*size[(i+1)%6];
    }
    cout<<(big_square_size-small_square_size)*k;
    
    return 0;
}
