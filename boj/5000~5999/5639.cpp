/*
upper_bound를 찾아 트리를 루트 노드, 왼쪽 부분, 오른쪽 부분으로 나눈 뒤
후위 연산이므로 왼쪽 -> 오른쪽 -> 루트 순서로 탐색 합니다.
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

int UpperBound(int start, int end, int key)
{
    int s = start, e = end+1;

    while (s<e)
    {
        int mid = (s+e)/2;

        if(key>=nums[mid])
            s = mid+1;
        else
            e = mid;
    }
    
    return s;
}

void Divide(int start, int end)
{
    if(start>end)
        return;
    
    int upper_bound = UpperBound(start, end, nums[start]);
    Divide(start+1, upper_bound-1);
    Divide(upper_bound, end);
    cout<<nums[start]<<'\n';
}

int main()
{
    while (true)
    {
        int num;
        cin>>num;
        if(cin.eof())
            break;
        nums.push_back(num);
    }
    
    Divide(0, nums.size()-1);

    return 0;
}
