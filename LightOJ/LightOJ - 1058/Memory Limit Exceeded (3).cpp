/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-30 21:57:20                      
*  solution_verdict: Memory Limit Exceeded                   language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1058
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,tc,n;
map<pair<int,int>,int>mp;
struct point
{
    int a,b;
}p[1003];
int main()
{
    cin>>t;
    while(t--)
    {
        mp.clear();
        cin>>n;
        for(int i=1;i<=n;i++)cin>>p[i].a>>p[i].b;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                mp[{p[i].a+p[j].a,p[i].b+p[j].b}]++;
            }
        }
        int ans=0;
        for(map<pair<int,int>,int>::iterator it=mp.begin();it!=mp.end();it++)
        {
            int x=it->second;
            ans=ans+(x*(x-1))/2;
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
    return 0;
}