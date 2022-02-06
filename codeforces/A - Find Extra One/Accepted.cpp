/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/21/2017 22:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/900/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,y,cnt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>x>>y;
        if(x>=0)cnt++;
    }
    if(cnt>=n-1||cnt<=1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
     return 0;
}
 