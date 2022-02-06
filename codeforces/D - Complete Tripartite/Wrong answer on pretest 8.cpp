/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/29/2019 20:14                        
*  solution_verdict: Wrong answer on pretest 8               language: GNU C++14                               
*  run_time: 170 ms                                          memory_used: 18000 KB                             
*  problem: https://codeforces.com/contest/1228/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int one[N+2],two[N+2],thr[N+2];
vector<int>adj[N+2];
void no()
{
  cout<<-1<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;vector<pair<int,int> >ed;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    ed.push_back({u,v});
  }
  for(int i=1;i<=n;i++)if(adj[i].size()==0)no();
   int id=-1;
  for(auto x:adj[1])two[x]=1,id=x;
  for(int i=1;i<=n;i++)if(two[i]==0)one[i]=1;
   if(id==-1)no();
   for(auto x:adj[id])
    if(two[x]==1)thr[x]=1,two[x]=0;
    for(auto x:ed)
  {
    if(thr[x.first]&&thr[x.second])no();
    if(two[x.first]&&thr[x.second])no();
    if(one[x.first]&&one[x.second])no();
  }
//  for(int i=1;i<=n;i++)
//    cout<<two[i];
//  cout<<endl;
  int on=0,tw=0,th=0;
  for(int i=1;i<=n;i++)
    on+=one[i],tw+=two[i],th+=thr[i];
   //cout<<on<<" "<<tw<<" "<<th<<endl;
  long tt=1LL*on*(1LL*tw+1LL*th)+1LL*tw*th;
  if(tt!=m)no();if(on+tw+th!=n)no;
  if(!on||!tw||!th)no();
   for(int i=1;i<=n;i++)
  {
    if(one[i])cout<<1<<" ";
    else if(two[i])cout<<2<<" ";
    else cout<<3<<" ";
  }
  cout<<endl;
  return 0;
}