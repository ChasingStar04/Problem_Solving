//convex hull trick을 이용하여 문제를 해결합니다.
#include <iostream>
#include <vector>

using namespace std;

struct LinearFunc  //일차함수 y = ax+b
{
    long long a;  //계수
    long long b;  //상수항
    double cx;  //앞 함수와의 교점의 x좌표
};

//직선 line1와 line2의 교점의 x좌표를 구합니다
double Cross(LinearFunc line1, LinearFunc line2)
{
    return ((double)line2.b-line1.b)/(line1.a-line2.a);
}

int main()
{
    int n;
    long long a[100010] = {0}, b[100010] = {0};
    long long dp[100010] = {0};
    vector<LinearFunc> fstk;  //일차함수들을 저장하는 스택

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++)
        cin>>b[i];
    
    for(int i=1; i<n; i++)
    {
        LinearFunc newf = {b[i-1], dp[i-1], 0};
        while (!fstk.empty())  //새 함수를 스택에 넣습니다.
        {
            newf.cx = Cross(fstk[fstk.size()-1], newf);
            if(fstk.back().cx<newf.cx)
                break;
            fstk.pop_back();
        }
        fstk.push_back(newf);
        
        long long x = a[i];
        int fpos = fstk.size()-1;
        if(x<fstk.back().cx)  //최솟값을 이분 탐색으로 찾습니다.
        {
            int first = 0, last = fstk.size()-1;
            while(first<last)
            {
                int mid = (first+last+1)/2;
                if(fstk[mid].cx<=x)
                    first = mid;
                else
                    last = mid-1;
            }
            fpos = first;
        }
        dp[i] = fstk[fpos].a*x+fstk[fpos].b;
    }

    cout<<dp[n-1];

    return 0;
}
