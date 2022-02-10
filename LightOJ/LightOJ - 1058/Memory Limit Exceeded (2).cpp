/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-30 21:59:12                      
*  solution_verdict: Memory Limit Exceeded                   language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1058
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,tc,n;
map<pair<long,long>,long>mp;
struct polong
{
    long a,b;
}p[1003];
int main()
{
    cin>>t;
    while(t--)
    {
        mp.clear();
        cin>>n;
        for(long i=1;i<=n;i++)cin>>p[i].a>>p[i].b;
        for(long i=1;i<=n;i++)
        {
            for(long j=i+1;j<=n;j++)
            {
                mp[{p[i].a+p[j].a,p[i].b+p[j].b}]++;
            }
        }
        long ans=0;
        for(map<pair<long,long>,long>::iterator it=mp.begin();it!=mp.end();it++)
        {
            long x=it->second;
            ans=ans+(x*(x-1))/2;
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
    return 0;
}