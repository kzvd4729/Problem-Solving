/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-15 00:01:07                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-924
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
vector<long>adj[25005];
long x,z,e,vis[25005],cnt[25005],t;
queue<pair<long,long> >q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>e)
    {
        for(long i=0;i<=25000;i++)adj[i].clear();
        for(long i=0;i<e;i++)
        {
            cin>>x;
            while(x--)
            {
                cin>>z;
                adj[i].push_back(z);
            }
        }
        cin>>t;
        while(t--)
        {
            while(q.size())q.pop();
            memset(cnt,0,sizeof(cnt));
            long mx=0,day;
            memset(vis,0,sizeof(vis));

            cin>>x;
            q.push({x,0});
            vis[x]=1;
            while(q.size())
            {
                long u=q.front().first;
                long v=q.front().second;
                q.pop();
                if(v!=0)cnt[v]++;
                if(cnt[v]>mx)
                {
                    mx=cnt[v];
                    day=v;
                }
                for(long i=0;i<adj[u].size();i++)
                {
                    long z=adj[u][i];
                    if(vis[z]==0)
                    {
                        q.push({z,v+1});
                        vis[z]=1;
                    }
                }

            }
            if(mx==0)cout<<0<<endl;
            else cout<<mx<<" "<<day<<endl;
        }
    }
    return 0;
}