//책을 고르는 모든 경우의 수 2^16 = 65536. 이정도는 껌이지 ㅋㅋㅋㅋㅋㅋ
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct pa
{
    int price;
    int alpha[26];
};

bool cmp(pa a, pa b){return a.price<b.price;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pa> v;
    string t, w;
    int n, c;

    cin>>t;
    cin>>n;

    pa p = {0};
    v.push_back(p);
    for (int i=0; i<n; i++)
    {
        cin>>c>>w;
        int vs = v.size();
        for (int j=0; j<vs; j++)
        {
            pa nowpa = v[j];
            nowpa.price += c;
            for (char &j : w)
                nowpa.alpha[j-'A']++;
            v.push_back(nowpa);
        }
    }

    sort(v.begin(), v.end(), cmp);
    int talpha[26] = {0};
    bool canmake;
    for (char &i : t)
        talpha[i-'A']++;
    
    for (pa &nowpa : v)
    {
        canmake = true;
        for (int i=0; i<26; i++)
        {
            if (talpha[i]>nowpa.alpha[i])
            {
                canmake = false;
                break;
            }
        }
        if (canmake)
        {
            cout<<nowpa.price;
            break;
        }
    }
    if (!canmake)
        cout<<-1;
    
    return 0;
}
