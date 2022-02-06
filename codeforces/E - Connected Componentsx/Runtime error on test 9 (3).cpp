/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/10/2018 17:12                        
*  solution_verdict: Runtime error on test 9                 language: GNU C++14                               
*  run_time: 358 ms                                          memory_used: 16900 KB                             
*  problem: https://codeforces.com/contest/920/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,u,v,cnt;
set<long>adj[100005],rem;
set<long>::iterator it;
vector<long>ans;
void dfs(long node)
{
    rem.erase(node);
    cnt++;
    for(it=rem.begin();it!=rem.end(); )
    {
        if(adj[node].count(*it))
        {
            it++;
            continue;
        }
        long tmp=*it;
        dfs(tmp);
        it=rem.lower_bound(tmp);
    }
    adj[node].clear();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    for(long i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for(long i=1;i<=n;i++)rem.insert(i);
    for(long i=1;i<=n;i++)
    {
        if(rem.count(i))
        {
            cnt=0;
            dfs(i);
            ans.push_back(cnt);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;
    return 0;
}
 