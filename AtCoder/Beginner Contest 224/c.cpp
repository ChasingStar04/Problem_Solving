//AC
/*
삼각형이 만들어지지 않을 때는 세 점이 한 직선 위에 있을 때 입니다.
점 a, b, c가 있을 때 선분 ab의 기울기와 선분 ac의 기울기가 같은지 검사합니다.
점들의 x좌표, y좌표가 모두 정수이므로 두 점의 x값의 차이와 y값의 차이를 구한 후 각각 둘의 최대공약수로 나눠 기울기를 기약분수 형태로 만들 수 있습니다.
두 기울기를 비교할 때는 기울기의 분자, 분모가 같은지 확인합니다.
*/
#include <iostream>
#include <cstdlib>

using namespace std;

struct Data
{
    int x;
    int y;
};

int GCD(int a, int b)
{
    if (b==0)
        return a;
    else
        return GCD(b, a%b);
}

Data Gradient(Data p1, Data p2)
{
    Data ans;
    int gcdxy;

    ans.x = p1.x-p2.x;
    ans.y = p1.y-p2.y;
    
    if (ans.x<0 && ans.y<0)
    {
        ans.x *= -1;
        ans.y *= -1;
    }
    gcdxy = GCD(ans.x, ans.y);
    ans.x /= gcdxy;
    ans.y /= gcdxy;

    return ans;
}

int main()
{
    int n, cnt = 0;
    Data arr[310] = {0};

    cin>>n;
    for (int i=0; i<n; i++)
        cin>>arr[i].x>>arr[i].y;
    
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            for (int k=j+1; k<n; k++)
            {
                Data gra1 = Gradient(arr[i], arr[j]), gra2 = Gradient(arr[i], arr[k]);
                if (!(gra1.x==gra2.x && gra1.y==gra2.y))
                    cnt++;
            }
        }
    }
    cout<<cnt;

    return 0;
}
