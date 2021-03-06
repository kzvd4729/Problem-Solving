/****************************************************************************************
*  @author: JU_Quanta: kzvd4729, tariqiitju, mh755628#       created: Sep/26/2019 16:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/690/problem/D2
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6,mod=1e6+3;
int fac[N+2];
int big(int b,int p)
{
    int ret=1;
    while(p)
    {
        if(p%2)ret=(1LL*ret*b)%mod;
        b=(1LL*b*b)%mod;p/=2;
    }
    return ret;
}
int ncr(int n,int r)
{
    int ret=fac[n];
    ret=(1LL*ret*big(fac[r],mod-2))%mod;
    return (1LL*ret*big(fac[n-r],mod-2))%mod;
}
int main()
{
    fac[0]=1;
    for(int i=1;i<=N;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
    int n,c;cin>>n>>c;int ans=0;
    for(int i=1;i<=n;i++)
        ans=(1LL*ans+1LL*ncr(i+c-1,c-1))%mod;
    cout<<ans<<endl;
    return 0;
}