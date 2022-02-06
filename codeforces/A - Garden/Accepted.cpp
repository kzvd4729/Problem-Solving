/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/13/2018 19:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/915/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>k;
    long ans=999999999999;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        if(k%x==0)ans=min(ans,k/x);
    }
    cout<<ans<<endl;
    return 0;
}