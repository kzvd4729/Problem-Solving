/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-02 19:01:01                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 292                                        memory_used (MB): 9.6                             
*  problem: https://vjudge.net/problem/LightOJ-1044
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1000000007;
long t,l,pre[1004],suf[1004],bs,m1,m2,pal[1003][1003],tc,dp[1003],pw[1003],inv[1003];
char s[1004];
long bigmod(long b,long p)
{
    long ret=1;
    while(p)
    {
        if(p&1)ret=(ret*b)%mod;
        b=(b*b)%mod;
        p/=2;
    }
    return ret;
}
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        pw[0]=1;
        for(long i=1;i<=1000;i++)pw[i]=(pw[i-1]*29)%mod;
        for(long i=0;i<=1000;i++)inv[i]=bigmod(pw[i],mod-2)%mod;

        scanf("%s",s);
        l=strlen(s);
        pre[0]=0;
        pre[1]=s[0];
        bs=1;
        for(long i=2;i<=l;i++)
        {
            bs=(bs*29)%mod;
            pre[i]=(pre[i-1]+s[i-1]*bs)%mod;
        }
        suf[l+1]=0;
        suf[l]=s[l-1];
        bs=1;
        for(long i=l-1;i>=1;i--)
        {
            bs=(bs*29)%mod;
            suf[i]=(suf[i+1]+s[i-1]*bs)%mod;
        }
        memset(pal,0,sizeof(pal));
        for(long i=1;i<=l;i++)
        {
            for(long j=i;j<=l;j++)
            {
                m1=((pre[j]-pre[i-1]+mod)*inv[i-1])%mod;
                m2=((suf[i]-suf[j+1]+mod)*inv[l-j])%mod;
                if(m1==m2)pal[i][j]=1;
            }
        }
        for(long i=1;i<=l;i++)dp[i]=9999999999;
        dp[0]=0;
        for(long i=1;i<=l;i++)
        {
            for(long j=1;j<=i;j++)
            {
                if(pal[j][i])dp[i]=min(dp[i],dp[j-1]+1);
            }
        }
        printf("Case %lld: %lld\n",++tc,dp[l]);
    }
    return 0;
}