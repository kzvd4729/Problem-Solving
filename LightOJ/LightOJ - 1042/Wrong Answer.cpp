/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-10 13:30:25                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1042
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int vis[100];
int main()
{
    long long int t,n,x,tc=0,y,i;
    scanf("%lld",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%lld",&n);
        for(i=50;i>=0;i--)
        {
            if(pow(2,i)<=n)
            {
                vis[i]=1;
                n=n-pow(2,i);
            }
        }
        
        for(i=0;i<=50;i++)
        {
            if(vis[i]==1&&vis[i+1]==0)
            {
                vis[i]=0;
                vis[i+1]=1;
                break;
            }
        }
        long long int sum=0;
        for(i=0;i<=50;i++)
        {
            if(vis[i]==1)
            {
                sum=sum+pow(2,i);
            }
        }
        printf("Case %lld: %lld\n",++tc,sum);
    }
    return 0;
}