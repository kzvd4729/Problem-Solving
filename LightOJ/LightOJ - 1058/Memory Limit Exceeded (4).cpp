/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-12-08 10:29:20                      
*  solution_verdict: Memory Limit Exceeded                   language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1058
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,u,v,ans,t,tc;
map<pair<long,long>,long>mp;
struct data
{
    long u;
    long v;
} arr[2002];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        mp.clear();
        cin>>n;
        for(long i=1; i<=n; i++)
        {
            cin>>arr[i].u>>arr[i].v;
        }
        for(long i=1; i<=n; i++)
        {
            for(long j=i+1; j<=n; j++)
            {
                mp[ {arr[i].u+arr[j].u,arr[i].v+arr[j].v}]++;
            }
        }
        ans=0;
        for(map<pair<long,long>,long>::iterator it=mp.begin();it!=mp.end();it++)
        {
            long z=it->second;
            ans+=((z*(z-1))/2);
        }
        /*for(auto x:mp)
        {
            long z=x.second;
            ans+=((z*(z-1))/2);
        }*/
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
    return 0;
}