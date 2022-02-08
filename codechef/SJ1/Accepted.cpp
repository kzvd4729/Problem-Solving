/****************************************************************************************
*  @author: kzvd4729                                         created: 07-04-2019 19:07:05                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.51 sec                                        memory_used: 19.3M                                
*  problem: https://www.codechef.com/APRIL19A/problems/SJ1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long aa[N+2],md[N+2];
vector<long>adj[N+2];
vector<pair<long,long> >ans;
void dfs(long node,long par,long gc)
{
  long cnt=0;
  for(auto x:adj[node])
  {
    if(x==par)continue;cnt++;
    dfs(x,node,__gcd(gc,aa[x]));
  }
  if(!cnt)
  {
    gc=__gcd(gc,md[node]);
    ans.push_back({node,md[node]-gc});
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long n;cin>>n;
    for(long i=1;i<=n;i++)
      adj[i].clear();
    for(long i=1;i<n;i++)
    {
      long u,v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for(long i=1;i<=n;i++)
      cin>>aa[i];
    for(long i=1;i<=n;i++)
      cin>>md[i];
    ans.clear();dfs(1,-1,aa[1]);
    sort(ans.begin(),ans.end());
    if(ans.size()==0)assert(0);
    cout<<ans[0].second;
    for(long i=1;i<ans.size();i++)
      cout<<" "<<ans[i].second;
    cout<<endl;
  }
  return 0;
}