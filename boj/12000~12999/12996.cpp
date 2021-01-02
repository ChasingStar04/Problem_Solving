//https://chasingstar.tistory.com/21
#include <iostream>

#define DIVI 1000000007
using namespace std;

long long full_c[51];  //FullCombi 함수의 반환값을 저장하는 dp 배열
long long combi[51][51];  //Combination 함수의 반환값을 저장하는 dp 배열

//nCr을 구하는 함수
long long Combination(int n, int r)
{
    if(combi[n][r])
        return combi[n][r];
    else if(n<r)
    {
        combi[n][r] = 0;
        return combi[n][r];
    }
    else if(n==r || r==0)
    {
        combi[n][r] = 1;
        return combi[n][r];
    }
    else if(r==1)
    {
        combi[n][r] = n;
        return combi[n][r];
    }
    
    long long result = 0;
    result = Combination(n-1, r-1)+Combination(n-1, r);  //n번째를 포함하는 경우, 포함하지 않는 경우
    combi[n][r] =  result%DIVI;
    return combi[n][r];
}

//아무도 부르지 않는 곡이 생기는 경우를 포함하는 경우의 수
long long AllCombi(int s, int d, int k, int h)
{
    long long result = 1;
    result = (result*Combination(s, d))%DIVI;
    result = (result*Combination(s, k))%DIVI;
    result = (result*Combination(s, h))%DIVI;
    
    return result;
}

//아무도 부르지 않는 곡이 생기는 경우를 포함하지 않는 경우의 수
long long FullCombi(int s, int d, int k, int h)
{
    if(full_c[s])
        return full_c[s];
    else if(d+k+h<s || d>s || k>s || h>s)
        return 0;
    else
    {
        long long result = AllCombi(s, d, k, h);
        
        for(int i=s-1; i>0; i--)
            result = (result-FullCombi(i, d, k, h)*Combination(s, i)+DIVI)%DIVI;
        full_c[s] = result;
        return full_c[s];
    }
}

int main()
{
    int s, d, k, h;

    cin>>s>>d>>k>>h;

    cout<<FullCombi(s, d, k, h);

    return 0;
}
