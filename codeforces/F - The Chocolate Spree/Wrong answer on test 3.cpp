/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2020 12:32                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 23600 KB                             
*  problem: https://codeforces.com/contest/633/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define double long double
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
   ans=max(ans,a+b+aa[node]+up);
  ans=max(ans,a+b+aa[node]+ch);
  ans=max(ans,a+b+aa[node]+c);
   multiset<long>st,an;st.insert(0);an.insert(0);
  for(auto x:adj[node])
  {
    if(x!=par)st.insert(mx[x]),an.insert(dp[x]);
  }
  for(auto x:adj[node])
  {
    if(x==par)continue;
    st.erase(st.find(mx[x]));
    an.erase(an.find(dp[x]));
     dds(x,node,max(up,*st.rbegin()),max(ch,*an.rbegin())+aa[node]);
     st.insert(mx[x]);
    an.insert(dp[x]);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)cin>>aa[i];
   for(long i=1;i<n;i++)
  {
    long u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,0);//return 0;
  dds(1,0,0,0);cout<<ans<<endl;
  return 0;
}