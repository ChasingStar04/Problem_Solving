/*
i번째 최솟값을 계산할 때, L범위 밖에 있는 수는 고려할 가치가 없습니다.
또한 i번째 수가 들어왔을 때, 0~(i-1)번째 수 중 i번째 수 이상인 수는 더이상 고려할 가치가 없습니다.
최솟값에서 i번째 수에 밀리고, i번째 수보다 먼저 나가기 때문입니다.

덱을 만들어, 위 두 조건을 만족하는 수들만 덱에 있도록 합니다.
i번째 수가 들어오면, 뒤에서부터 i번째 수 이상인 수들을 빼내고
앞에서는 L범위를 벗어나면 빼냅니다. 이후 i번째 수를 뒤에 넣습니다.

이렇게 하면 덱은 L범위 안에서의 최소 증가 오름차순 수열이 됩니다.
맨 앞의 수가 L범위를 벗어나 나가면, 그 다음 수가 최솟값이 됩니다.
*/
#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, num;
    deque<pair<int, int>> dq;

    cin>>n>>l;
    for (int i=0; i<n; i++)
    {
        cin>>num;
        
        while (!dq.empty() && dq.back().first>=num)
            dq.pop_back();
        if (!dq.empty() && dq.front().second<(i-l+1))
            dq.pop_front();
        
        dq.push_back({num, i});
        cout<<dq.front().first<<' ';
    }

    return 0;
}
