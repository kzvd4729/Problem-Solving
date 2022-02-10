/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-15 12:54:56                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 4                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1174
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,tc,n,k,dis[102],u,v,s,d;
vector<long>adj[102];
queue<long>q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        for(long i=0;i<=100;i++)adj[i].clear();

        cin>>n>>k;
        for(long i=1;i<=k;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cin>>s>>d;
        long ans=0;
        for(long i=0;i<n;i++)
        {
            while(q.size())q.pop();
            memset(dis,-1,sizeof(dis));

            q.push(i);
            dis[i]=0;

            while(q.size())
            {
                u=q.front();
                q.pop();
                for(long j=0;j<adj[u].size();j++)
                {
                    long z=adj[u][j];
                    if(dis[z]!=-1)continue;
                    dis[z]=dis[u]+1;
                    q.push(z);
                }
            }
            if(dis[s]==-1||dis[d]==-1)continue;
            ans=max(ans,dis[s]+dis[d]);
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }

    return 0;
}