/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-15 00:40:45                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 16                                         memory_used (MB): 2                               
*  problem: https://vjudge.net/problem/LightOJ-1111
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,k,n,m,cnt[1004],vis[1002],u,v,ans,x,tc;
vector<long>sr,adj[1004];
queue<long>q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        sr.clear();
        for(long i=0;i<=1000;i++)adj[i].clear();

        cin>>k>>n>>m;
        for(long i=1;i<=k;i++)
        {
            cin>>x;
            sr.push_back(x);
        }
        for(long i=1;i<=m;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
        for(long i=0;i<sr.size();i++)
        {
            memset(vis,0,sizeof(vis));
            while(q.size())q.pop();

            q.push(sr[i]);
            vis[sr[i]]=1;
            cnt[sr[i]]++;
            while(q.size())
            {
                long z=q.front();
                q.pop();
                for(long j=0;j<adj[z].size();j++)
                {
                    long zz=adj[z][j];
                    if(vis[zz])continue;
                    vis[zz]=1;
                    cnt[zz]++;
                    q.push(zz);
                }
            }

        }
        ans=0;
        for(long i=1;i<=n;i++)
        {
            if(cnt[i]==k)ans++;
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;

    }

    return 0;
}