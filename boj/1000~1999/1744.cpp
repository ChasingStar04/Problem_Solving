//https://chasingstar.tistory.com/23
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<int> positive, negative;
    long long result = 0;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        int tmp;
        cin>>tmp;
        if (tmp==1)
            result++;
        else if (tmp>0)
            positive.push_back(tmp);
        else
            negative.push_back(tmp);
    }
    
    sort(positive.begin(), positive.end(), greater<int>());
    for (int i=1; i<positive.size(); i+=2)
        result += (long long)positive[i-1]*positive[i];
    if (positive.size()%2)
        result += (long long)positive[positive.size()-1];

    sort(negative.begin(), negative.end());
    for (int i=1; i<negative.size(); i+=2)
        result += (long long)negative[i-1]*negative[i];
    if (negative.size()%2)
        result += (long long)negative[negative.size()-1];
    
    cout<<result;

    return 0;
}
