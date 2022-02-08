/****************************************************************************************
*  @author: kzvd4729                                         created: 08-11-2018 23:10:34                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.19 sec                                        memory_used: 34.1M                                
*  problem: https://www.codechef.com/NOV18A/problems/PRITREE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const int R=2e7;
bool vis[R+2];
int aa[N+2];
vector<int>adj[N+2];
int dfs(int node,int par)
{
  int here=aa[node];
  for(auto x:adj[node])
  {
    if(x==par)continue;
    here+=dfs(x,node);
  }
  return here;
}
void seive(void)
{
  vis[0]=1,vis[1]=1;int sq=sqrt(R+1);
  for(int i=4;i<=R;i+=2)vis[i]=1;
  for(int i=3;i<=R;i+=2)
  {
    if(vis[i])continue;
    if(i>sq)continue;
    for(int j=i*i;j<=R;j+=2*i)
      vis[j]=1;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];
  }
  set<pair<int,int> >sb,av;
  vector<pair<int,int> >ed,pn;
  int rt=-1;
  for(int i=1;i<=n;i++)
  {
    if(!vis[aa[i]])
      sb.insert({i,aa[i]});
    else 
    {
      if(rt==-1)rt=i;
      else pn.push_back({i,aa[i]});
    }
  }
  int loop=200;
  while(loop--)
  {
    for(auto x:pn)av.insert(x);pn.clear();
    while(av.size())
    {
      pair<int,int>p=*av.begin();av.erase(p);
      int f=0;
      for(auto x:sb)
      {
        if(!vis[x.second+p.second])
        {
          sb.erase(x);f=1;
          ed.push_back({x.first,p.first});
          sb.insert({p.first,x.second+p.second});
          break;
        }
      }
      if(f==0)
        pn.push_back(p);
    }
  }
  for(auto x:pn)av.insert(x);pn.clear();
  while(av.size())
  {
    pair<int,int>p=*av.begin();av.erase(p);
    int f=0;
    for(auto x:sb)
    {
      if(!vis[x.second+p.second])
      {
        sb.erase(x);f=1;
        ed.push_back({x.first,p.first});
        sb.insert({p.first,x.second+p.second});
        break;
      }
    }
    if(f==0)
    {
      auto x=sb.begin();
      sb.erase(x);
      ed.push_back({x->first,p.first});
      sb.insert({p.first,x->second+p.second});
    }
  }
  for(auto x:sb)
    ed.push_back({rt,x.first});
  for(auto x:ed)
    cout<<x.first<<" "<<x.second<<"\n";
  // for(auto x:ed)
  // {
  //   adj[x.first].push_back(x.second);
  //   adj[x.second].push_back(x.first);
  // }
  // int cnt=0;
  // for(auto x:ed)
  // {
  //   if(!vis[dfs(x.first,x.second)])cnt++;
  //   if(!vis[dfs(x.second,x.first)])cnt++;
  // }
  // cout<<cnt<<endl;
  return 0;
}