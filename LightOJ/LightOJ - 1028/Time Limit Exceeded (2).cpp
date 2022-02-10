/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-14 21:39:49                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1028
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
long vis[1000004];
long t,n,x,p,m,tc;
vector<long>prime;
void seive(void)
{
    prime.push_back(2);
    long lim=sqrt(1000000)+2;
    for(long i=3;i<=1000000;i=i+2)
    {
        if(vis[i]==0)
        {
            prime.push_back(i);
            if(i<=lim)
            {
                for(long j=i*i;j<=1000000;j=j+2*i)
                {
                    vis[j]=1;
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive();
    cin>>t;
    while(t--)
    {
        cin>>n;
        x=sqrt(n);
        m=1;
        for(long i=0;i<prime.size();i++)
        {
            if(prime[i]>x||prime[i]>n)break;
            p=0;
            while(n%prime[i]==0)
            {
                n=n/prime[i];
                p++;
            }
            m=m*(p+1);
        }
        if(n!=1)m=m*2;
        m--;
        cout<<"Case "<<++tc<<": "<<m<<endl;
    }
    return 0;
}