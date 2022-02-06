/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/24/2017 20:47                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/855/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,p,q,x,r,mx=-9999999999999999,mn=99999999999999,ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>p>>q>>r;
    while(n--)
    {
        cin>>x;
        mx=max(mx,x);
        mn=min(mn,x);
    }
    if(p<0)ans+=p*mn;
    else ans+=p*mx;
    if(q<0)ans+=q*mn;
    else ans+=q*mx;
    if(r<0)ans+=r*mn;
    else ans+=r*mx;
    cout<<ans<<endl;
    return 0;
}