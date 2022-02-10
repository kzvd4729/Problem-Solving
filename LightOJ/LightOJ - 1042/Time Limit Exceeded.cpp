/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-10 11:29:16                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1042
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int bin(long long int n)
{
    int one=0;
    while(n)
    {
        if(n&1)
        {
            n--;
            one++;
        }
        n=n/2;
    }
    return one;
}
int main()
{
    long long int t,n,x,tc=0,y,i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        x=bin(n);
        if(x==1)
        {
            printf("Case %lld: %lld\n",++tc,n*2);
        }
        else
        {
            for(i=n+1;  ; i++)
            {
                y=bin(i);
                if(y==x)break;
            }
            printf("Case %lld: %lld\n",++tc,i);
        }
    }
    return 0;
}