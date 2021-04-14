//https://chasingstar.tistory.com/24
#include <iostream>

using namespace std;

int arr[1010][1010];

void Move(char dire, int len)
{
    for (int i=0; i<len; i++)
        cout<<dire;
    return;
}

int main()
{
    int r, c, minx = 1, miny = 0;
    
    cin>>r>>c;
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            cin>>arr[i][j];
            if ((i+j)%2 && arr[i][j]<arr[miny][minx])
            {
                miny = i;
                minx = j;
            }
        }
    }

    if (r%2)
    {
        Move('R', c-1);
        for (int i=0; i<r-1; i++)
        {
            Move('D', 1);
            Move((i%2==0 ? 'L' : 'R'), c-1);
        }
    }
    else if (c%2)
    {
        Move('D', r-1);
        for (int i=0; i<c-1; i++)
        {
            Move('R', 1);
            Move((i%2==0 ? 'U' : 'D'), r-1);
        }
    }
    else //가로와 세로 모두 짝수인 경우
    {
        bool pass = false;

        for (int i=0; i<r; i+=2)
        {
            if (miny==i || miny==i+1)
            {
                bool up_or_down = false;
                pass = true;

                if (i!=0) Move('D', 1);
                for (int j=0; j<c; j++)
                {
                    if (j!=0) Move('R', 1);
                    if (j!=minx)
                    {
                        if (up_or_down) Move('U', 1);
                        else Move('D', 1);
                        up_or_down = !up_or_down;
                    }
                }
            }
            else
            {
                if (i!=0) Move('D', 1);
                if (pass)
                {
                    Move('L', c-1);
                    Move('D', 1);
                    Move('R', c-1);
                }
                else
                {
                    Move('R', c-1);
                    Move('D', 1);
                    Move('L', c-1);
                }
            }
        }
    }
    return 0;
}
