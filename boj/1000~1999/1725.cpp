/*
접근) 새 칸이 들어오면, 새 칸보다 높은 직사각형은 더 이상 커질 여지가 없습니다.
높이가 h인 새 칸이 들어왔을 때 새 칸을 포함하여 만들 수 있는 1~h 높이의 직사각형을 모두 계산하는 것은 비효율적이므로,
더 이상 커질 여지가 없는 h보다 높은 칸에서 시작하는 직사각형의 넓이만 계산합니다.
모든 칸이 들어오면 아직 계산하지 않은 칸을 높이로 하는 직사각형의 넓이를 계산합니다.
이것을 칸의 높이와 idx(순서)를 담는 스택을 이용해 구현할 수 있습니다.

여기서 주의해야 될 점은, 예를들어 5 4 높이의 칸이 순서대로 들어온다고 하면
높이가 4인 칸이 두 번째로 들어왔지만 높이가 4인 직사각형은 1열부터 시작할 수 있다는 것입니다.
이때 직사각형의 최대 넓이는 4*2=8 입니다.
이 문제를 해결하기 위해, 새 칸이 들어오면 새 칸보다 높이가 높거나 같은 칸의 넓이를 계산한 후 빼내고
스택에 넣을 때 idx를 min(높이가 높거나 같은 칸의 idx)로 넣습니다.
*/
#include <iostream>
#include <stack>

using namespace std;

struct hi
{
    int height;
    int idx;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num, idx;
    long long ans = 0;
    stack<hi> stk;
    
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>num;
        idx = i;
        while (!stk.empty() && stk.top().height>=num)
        {
            ans = max(ans, (long long)stk.top().height*(i-stk.top().idx));
            idx = stk.top().idx;
            stk.pop();
        }
        stk.push({num, idx});
    }
    while (!stk.empty())
    {
        ans = max(ans, (long long)stk.top().height*(n-stk.top().idx));
        stk.pop();
    }
    cout<<ans<<'\n';
    
    return 0;
}
