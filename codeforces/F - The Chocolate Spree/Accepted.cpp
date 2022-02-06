/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2020 13:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 77800 KB                             
*  problem: https://codeforces.com/contest/633/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long aa[N+2],dp[N+2],mx[N+2];
vector<long>adj[N+2];
void dfs(long node,long par)
{
  priority_queue<long>pq;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);pq.push(dp[x]);
    dp[node]=max(dp[node],dp[x]);
  }
  dp[node]+=aa[node];
    mx[node]=aa[node];
  if(pq.size())
  {
    mx[node]+=pq.top();pq.pop();
  }
  if(pq.size())
  {
    mx[node]+=pq.top();pq.pop();
  }
  for(auto x:adj[node])
  {
    if(x!=par)mx[node]=max(mx[node],mx[x]);
  }
}
long ans;
void dds(long node,long par,long up,long ch)
{
  priority_queue<long>pq;pq.push(0);pq.push(0);pq.push(0);
  for(auto x:adj[node])
  {
    if(x!=par)pq.push(dp[x]);
  }
  long a=pq.top();pq.pop();
  long b=pq.top();pq.pop();
  long c=pq.top();pq.pop();
   //if(node==2)cout<<up<<endl;
   ans=max(ans,a+b+aa[node]+up);
  ans=max(ans,a+b+aa[node]+ch);
  ans=max(ans,a+b+aa[node]+c);
   multiset<long>st,an;st.insert(0);an.insert(0);an.insert(0);
  for(auto x:adj[node])
  {
    if(x!=par)st.insert(mx[x]),an.insert(dp[x]);
  }
  for(auto x:adj[node])
  {
    if(x==par)continue;long ad=0;
    st.erase(st.find(mx[x]));
    an.erase(an.find(dp[x]));
     auto it=an.rbegin();
    ad+=*it;long str=ad;
    an.erase(an.find(str));
    ad+=*an.rbegin();an.insert(str);
    ad+=aa[node];
    dds(x,node,max({up,*st.rbegin(),ch+*an.rbegin()+aa[node],ad}),max(ch,*an.rbegin())+aa[node]);
     st.insert(mx[x]);
    an.insert(dp[x]);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,0);//return 0;
  dds(1,0,0,0);cout<<ans<<endl;
  return 0;
}