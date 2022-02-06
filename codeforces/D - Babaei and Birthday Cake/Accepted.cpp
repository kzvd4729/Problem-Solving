/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2017 19:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 11200 KB                             
*  problem: https://codeforces.com/contest/629/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long int
using namespace std;
long n,i,r,h,vol[100005],dp[100005],sorted[100005],bit[100005],ans,id,sx;
vector<pair<long,long> >v;
map<long,long>mp;
void upd(long idx,long delta)
{
    for( ;idx<=n;idx+=idx&-idx)
    {
        bit[idx]=max(bit[idx],delta);
    }
}
long query(long idx)
{
    idx--;
    sx=0;
    for( ;idx>=1;idx-=idx&-idx)
    {
        sx=max(sx,bit[idx]);
    }
    return sx;
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>r>>h;
        v.push_back(make_pair(r,h));
        vol[i]=r*r*h;
        sorted[i]=vol[i];
    }
    sort(sorted+1,sorted+n+1);
    for(i=1;i<=n;i++)
    {
        mp[sorted[i]]=i;
    }
     for(i=1;i<=n;i++)
    {
        id=mp[vol[i]];
        dp[id]=vol[i]+query(id);
        upd(id,dp[id]);
        ans=max(ans,dp[id]);
    }
    double ns=(double)ans*acos(-1);
    cout<<setprecision(15)<<ns<<endl;
     return 0;
}