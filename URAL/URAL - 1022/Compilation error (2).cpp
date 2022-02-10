/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-15 11:12:46                      
*  solution_verdict: Compilation error                       language: Go 1.3                                  
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/URAL-1022
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long cnt[102],n,now,nw,x;
vector<long>adj[102],ans;
priority_queue<pair<long,long> >pq;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(long i=1;i<=n;i++)
    {
        while(cin>>x)
        {
            if(x==0)break;
            adj[x].push_back(i);
            cnt[i]++;
        }
        pq.push({-cnt[i],i});
    }
    for(long i=1;i<=n;i++)
    {
        now=pq.top().second;
        pq.pop();
        ans.push_back(now);
        for(long j=0;j<adj[now].size();j++)
        {
            long z=adj[now][j];
            cnt[z]--;
            pq.push({-cnt[z],z});
        }
    }
    for(long i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}