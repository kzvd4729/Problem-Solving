/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/09/2017 22:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/706/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n;
double a,b,x,y,ans,v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>a>>b;
    cin>>n;
    ans=999999999999999;
    for(long i=1;i<=n;i++)
    {
        cin>>x>>y>>v;
        ans=min(ans,sqrt((a-x)*(a-x)+(b-y)*(b-y))/v);
    }
    cout<<setprecision(14)<<fixed<<ans<<endl;
    return 0;
}
 