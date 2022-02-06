/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/04/2019 23:38                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 93 ms                                           memory_used: 44800 KB                             
*  problem: https://codeforces.com/gym/102346/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
int mx[N+2],big[N+2];
vector<int>adj[N+2];
priority_queue<pair<int,int> >pq;
void dfs(int node)
{
  int now=0;
  for(auto x:adj[node])
  {
    dfs(x);
    if(mx[x]>now)now=mx[x],big[node]=x;
  }
  mx[node]=now+1;
}
void del(int node)
{
  if(!big[node])return ;
  for(auto x:adj[node])
    if(x!=big[node])pq.push({mx[x],x});
  del(big[node]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;
  for(int i=2;i<=n;i++)
  {
    int x;cin>>x;
    adj[x].push_back(i);
  }
  dfs(1);pq.push({mx[1],1});
   int ans=0;
  while(k--)
  {
    if(pq.size()==0)break;
    pair<int,int>p=pq.top();pq.pop();
    ans+=p.first;
     del(p.second);
  }
  cout<<ans<<endl;
  return 0;
}