/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/10/2018 18:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 311 ms                                          memory_used: 37200 KB                             
*  problem: https://codeforces.com/contest/920/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
set<long>adj[200005],st;
long n,m,u,v,cnt;
vector<long>ans;
set<long>::iterator it;
void dfs(long node)
{
    st.erase(node);
    cnt++;
    for(it=st.begin();it!=st.end(); )
    {
        long tmp=*it;
        if(adj[node].count(tmp))
        {
            it++;
            continue;
        }
        dfs(tmp);
        it=st.upper_bound(tmp);
    }
    ///adj[node].clear();
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
    for(long i=1;i<=n;i++)st.insert(i);
    for(int i=1;i<=n;i++)
    {
        if(st.count(i))
        {
            cnt=0;
            dfs(i);
            ans.push_back(cnt);
        }
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;
    return 0;
}