/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-30 23:12:19                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 596                                        memory_used (MB): 14                              
*  problem: https://vjudge.net/problem/LightOJ-1058
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,tc,n;
vector<pair<long,long> >v;
struct point
{
    int a,b;
}p[1003];
int main()
{
    cin>>t;
    while(t--)
    {
        v.clear();
        cin>>n;
        for(int i=1;i<=n;i++)cin>>p[i].a>>p[i].b;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)v.push_back({p[i].a+p[j].a,p[i].b+p[j].b});
        }
        sort(v.begin(),v.end());
        long x=999999999999,y=999999999999,cnt=0,ans=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first!=x||v[i].second!=y)
            {
                ans=ans+(cnt*(cnt-1))/2;
                x=v[i].first;
                y=v[i].second;
                cnt=1;
            }
            else cnt++;
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
    return 0;
}