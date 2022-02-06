/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/17/2017 12:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/899/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,one,two;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        if(x==1)one++;
        else two++;
    }
     if(two>=one)cout<<one<<endl;
    else cout<<two+abs(two-one)/3<<endl;
     return 0;
}