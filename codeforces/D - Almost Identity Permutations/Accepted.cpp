/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/12/2017 14:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 156 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/888/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k;
long k4(void)
{
    long cnt=0;
    for(long i=1;i<=n;i++)
    {
        for(long j=i+1;j<=n;j++)
        {
            for(long k=j+1;k<=n;k++)
            {
                cnt+=(n-k);
            }
        }
    }
    return cnt;
}
long k3(void)
{
    long cnt=0;
    for(long i=1;i<=n;i++)
    {
        for(long j=i+1;j<=n;j++)
        {
            for(long k=j+1;k<=n;k++)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
long k2(void)
{
    long cnt=0;
    for(long i=1;i<=n;i++)
    {
        for(long j=i+1;j<=n;j++)
        {
            cnt++;
        }
    }
    return cnt;
}
long c4(void)
{
    long cnt=0;
    for(long i=1;i<=4;i++)
    {
        if(i==1)continue;
        for(long j=1;j<=4;j++)
        {
            if(j==i||j==2)continue;
            for(long k=1;k<=4;k++)
            {
                if(k==i||k==j||k==3)continue;
                for(long h=1;h<=4;h++)
                {
                    if(h==4||h==i||h==j||h==k)continue;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
long c3(void)
{
    long cnt=0;
    for(long i=1;i<=3;i++)
    {
        if(i==1)continue;
        for(long j=1;j<=3;j++)
        {
            if(j==i||j==2)continue;
            for(long k=1;k<=3;k++)
            {
                if(k==i||k==j||k==3)continue;
                cnt++;
            }
        }
    }
    return cnt;
}
long c2(void)
{
    long cnt=0;
    for(long i=1;i<=2;i++)
    {
        if(i==1)continue;
        for(long j=1;j<=2;j++)
        {
            if(j==i||j==2)continue;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>k;
    long ans;
    if(k==4)ans=(k4()*c4())+(k3()*c3())+(k2()*c2())+1;
    else if(k==3)ans=(k3()*c3())+(k2()*c2())+1;
    else if(k==2)ans=(k2()*c2())+1;
    else ans=1;
    cout<<ans<<endl;
    ///cout<<c2()<<endl;
     return 0;
}
 