/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/13/2018 14:00                        
*  solution_verdict: Time limit exceeded on test 10          language: GNU C++17                               
*  run_time: 2000 ms                                         memory_used: 9900 KB                              
*  problem: https://codeforces.com/contest/851/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long prime[32000],n,x,y,arr[1000005];
void seive(void)
{
    prime[1]=1;
    long lim=sqrt(32000)+1;
    for(long i=4;i<=32000;i+=2)prime[i]=1;
    for(long i=3;i<=32000;i+=2)
    {
        if(prime[i]==1)continue;
        if(i<=lim)
        {
            for(long j=i*i;j<=32000;j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     seive();
    cin>>n>>x>>y;
    for(long i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+n+1);
    long ans=99999999999999999;
    for(long i=2;i<=10000;i++)
    {
        if(prime[i]==1)continue;
        long sum=0;
        for(long j=1;j<=n;j++)
        {
            long u=i-(arr[j]%i);
            u=u%i;
            sum+=min(x,y*u);
            if(sum>ans)break;
        }
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
     return 0;
}