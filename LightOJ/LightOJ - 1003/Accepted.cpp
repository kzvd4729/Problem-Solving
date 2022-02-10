/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-15 13:18:33                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 144                                        memory_used (MB): 3.7                             
*  problem: https://vjudge.net/problem/LightOJ-1003
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,tc,n,id,cnt[10002];
map<string,long>mp;
vector<long>adj[10004];
priority_queue<pair<long,long> >pq;
string u,v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        for(long i=0;i<=10000;i++)adj[i].clear();
        mp.clear();
        memset(cnt,0,sizeof(cnt));

        cin>>n;
        id=0;
        for(long i=1;i<=n;i++)
        {
            cin>>u>>v;
            if(mp[u]==0)mp[u]=++id;
            if(mp[v]==0)mp[v]=++id;
            adj[mp[u]].push_back(mp[v]);
            cnt[mp[v]]++;
        }
        for(long i=1;i<=id;i++)
        {
            pq.push({-cnt[i],i});
        }
        ///cout<<pq.size()<<endl;
        long f=0;
        for(long i=1;i<=id;i++)
        {
            long z=pq.top().first;
            ///cout<<z<<endl;
            if(z!=0)
            {
                f=1;
                cout<<"Case "<<++tc<<": No"<<endl;
                break;
            }
            z=pq.top().second;
            pq.pop();
            for(long j=0;j<adj[z].size();j++)
            {
                long xx=adj[z][j];
                cnt[xx]--;
                pq.push({-cnt[xx],xx});
            }
        }
        if(f==0)cout<<"Case "<<++tc<<": Yes"<<endl;
    }
    return 0;
}