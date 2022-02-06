/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2018 12:22                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 6500 KB                              
*  problem: https://codeforces.com/contest/189/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long n,ans,po[N+2],now,cnt,r,x,bit[2*N];
void upd(long idx,long vl)
{
    for( ;idx<=n;idx+=idx&-idx)bit[idx]+=vl;
}
long query(long idx)
{
    long sum=0;
    for( ;idx>0;idx-=idx&-idx)sum+=bit[idx];
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        po[x]=i;
    }
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        now=po[x];
        now+=query(now);
        ///cout<<now<<endl;
        if(now<=i)continue;
        upd(1,1);
        upd(po[x],-1);
        ///ans=max(ans,n-now+1);
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}