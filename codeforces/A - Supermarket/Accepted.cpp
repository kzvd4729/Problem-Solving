/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/31/2018 19:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/919/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n;
double m,a,b,c,ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    ans=999999999.0;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        c=a/b;
        ans=min(ans,c*m);
    }
    cout<<setprecision(12)<<fixed<<ans<<endl;
    return 0;
}