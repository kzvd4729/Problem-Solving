/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-15 15:30:53                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10305
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long cnt[102],n,m,u,v;
vector<long>adj[102],ans;
priority_queue<pair<long,long> >pq;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n>>m)
    {
        if(!n&&!m)break;
        memset(cnt,0,sizeof(cnt));
        for(long i=0;i<=100;i++)adj[i].clear();
        while(pq.size())pq.pop();

        while(m--)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            cnt[v]++;
        }
        for(long i=1;i<=n;i++)
        {
            pq.push({-cnt[i],-i});
        }
        for(long i=1;i<=n;i++)
        {
            long x=-pq.top().second;
            ans.push_back(x);
            pq.pop();
            for(long j=0;j<adj[x].size();j++)
            {
                long z=adj[x][j];
                cnt[z]--;
                pq.push({-cnt[z],-z});
            }
        }
        for(long i=0;i<ans.size();i++)
        {
            cout<<ans[i];
            if(i==ans.size()-1)cout<<endl;
            else cout<<" ";
        }
    }
    return 0;
}