/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/19/2017 21:45                        
*  solution_verdict: Hacked                                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/902/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int go,a,b,n,m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
     cin>>a>>b;
     if(a>m)
    {
        cout<<"NO"<<endl;
        return 0;
    }
     go=b;
    for(long i=2;i<=n;i++)
    {
        cin>>a>>b;
        if(a<=go)
        {
            go=max(go,b);
        }
    }
    if(go>=m)
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}