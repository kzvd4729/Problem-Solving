/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-31 00:30:12                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 2048                                       memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1292
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc,ans,n;
struct point
{
    double a,b;
}p[1003];
double m;
map<long,int>mp;
int main()
{
    cin>>t;
    while(t--)
    {
        mp.clear();
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i].a>>p[i].b;
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            mp.clear();
            for(int j=1;j<=n;j++)
            {
                if(i==j)continue;
                m=(p[j].b-p[i].b)/(p[j].a-p[i].a);
                m=m*10000000000;
                long x=m;
                ///cout<<x<<endl;
                mp[x]++;
                ans=max(ans,mp[x]);
            }
        }
        cout<<"Case "<<++tc<<": "<<ans+1<<endl;
    }
    return 0;
}