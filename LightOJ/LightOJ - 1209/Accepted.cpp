/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-20 19:44:22                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 14                                         memory_used (MB): 2.5                             
*  problem: https://vjudge.net/problem/LightOJ-1209
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=500,inf=1e9;

bool used[N+2];int mt[N+2];
vector<int>adj[N+2];//only edge from left to right
bool tryKuhn(int v)
{
  if(used[v])return false;used[v]=true;
  for(auto u:adj[v])
  {
    if(mt[u]==-1||tryKuhn(mt[u]))
    {
      mt[u]=v;return true;
    }
  }
  return false;
}
bool usd[N+2];
int solve(int a,int b)
{
  for(int i=1;i<=b;i++)mt[i]=-1;
  for(int i=1;i<=a;i++)usd[i]=false;
  for(int i=1;i<=a;i++)
  {
    for(auto x:adj[i])
    {
      if(mt[x]!=-1)continue;
      mt[x]=i;usd[i]=true;break;
    }
  }
  for(int i=1;i<=a;i++)
  {
    if(usd[i])continue;
    for(int j=1;j<=a;j++)used[j]=false;
    tryKuhn(i);
  }
  int ret=0;
  for(int i=1;i<=b;i++)if(mt[i]!=-1)ret++;
  for(int i=1;i<=a;i++)adj[i].clear();
  return ret;
}
vector<pair<string,string> >aa,bb;
bool isConflict(int i,int j)
{
  if(aa[i].first==bb[j].second||aa[i].second==bb[j].first)return true;
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int t,tc=0;cin>>t;
  while(t--)
  {
    int a,b,c;cin>>a>>b>>c;aa.clear(),bb.clear();
    for(int i=1;i<=c;i++)
    {
      string x,y;cin>>x>>y;
      if(x[0]=='M')aa.push_back({x,y});
      else bb.push_back({x,y});
    }

    for(int i=0;i<aa.size();i++)
    {
      for(int j=0;j<bb.size();j++)
      {
        if(isConflict(i,j))
        {
          adj[i+1].push_back(j+1);
          //cout<<i<<" "<<j<<endl;
        }
      }
    }
    cout<<"Case "<<++tc<<": "<<c-solve(aa.size(),bb.size())<<"\n";
  }
  return 0;
}