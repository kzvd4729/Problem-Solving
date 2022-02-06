/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/12/2017 20:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/873/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,qm,ans;
string s;
map<long,long>mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    cin>>s;
    qm=0;
    for(long i=1;i<=n;i++)
    {
        if(s[i-1]=='1')qm++;
        else qm--;
        if(qm==0)ans=max(ans,i);
        else if(mp[qm]==0)mp[qm]=i;
        else ans=max(ans,i-mp[qm]);
    }
    cout<<ans<<endl;
    return 0;
}