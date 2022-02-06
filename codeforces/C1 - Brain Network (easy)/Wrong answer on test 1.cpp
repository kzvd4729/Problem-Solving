/****************************************************************************************
*  @author: JU_Quanta: kzvd4729, tariqiitju, mh755628#       created: Sep/26/2019 15:20                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/690/problem/C1
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
    for(int i=1;i<=c;i++)
    {
        int now=(1LL*ncr(n,i)*(c-i+1))%mod;
        ans=(1LL*ans+now)%mod;
    }
    cout<<ans<<endl;
    return 0;
}