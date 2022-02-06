/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/10/2020 14:21                        
*  solution_verdict: Time limit exceeded on test 54          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 43400 KB                             
*  problem: https://codeforces.com/contest/141/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6;
int cnt[2];
bitset<1000+2>vs;
vector<vector<int> >ad[N+2],sp[N+2];
vector<int>spn;
void dfs(int nd)
{
  vs[nd]=1;
  for(auto x:ad[nd])
  {
    if(vs[x[0]])continue;
    cnt[x[1]]++;spn.push_back(x[2]);
    sp[nd].push_back(x);sp[x[0]].push_back({nd,x[1],x[2]});
     dfs(x[0]);
  }
}
vector<int>pth;
bool dfs(int st,int tr)
{
  if(st==tr)return true;
  vs[st]=1;
  for(auto x:sp[st])
  {
    if(vs[x[0]])continue;
    pth.push_back(x[2]);
    if(dfs(x[0],tr))return true;
    pth.pop_back();
  }
  return false;
}
void no(){cout<<-1<<endl,exit(0);}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;if(n%2==0)no();
  vector<vector<int> >ed(m+2);set<vector<int> >s;
  for(int i=1;i<=m;i++)
  {
    char c;int u,v;cin>>u>>v>>c;
    int f=(c=='M');
    if(u>v)swap(u,v);
    if(s.find({u,v,c})!=s.end())u=1,v=1,c=0;
    s.insert({u,v,c});
     ad[u].push_back({v,f,i});
    ad[v].push_back({u,f,i});
    ed[i]={u,v,f};
  }
  dfs(1);if(cnt[0]+cnt[1]!=n-1)no();
  int tr=0;if(cnt[1]<cnt[0])tr=1;
   //cout<<cnt[0]<<" "<<cnt[1]<<endl;
  //cout<<tr<<endl;
  vector<int>xx;for(int i=1;i<=m;i++)xx.push_back(i);
  shuffle(xx.begin(),xx.end(),rng);
  for(int l=0;l<(int)xx.size();l++)
  {
    int i=xx[l];
    if(cnt[0]==cnt[1])break;
    if(ed[i][0]==ed[i][1])continue;
    if(ed[i][2]!=tr)continue;
     vs.reset();pth.clear();
    dfs(ed[i][0],ed[i][1]);
    int rp=-1;
    for(auto x:pth)
    {
      if(ed[x][2]==tr)continue;
      rp=x;break;
    }
    if(rp==-1)continue;
    int u=ed[rp][0],v=ed[rp][1];
     int id=0;
    for(auto x:sp[u])
    {
      if(x[2]==rp)
      {
        sp[u].erase(sp[u].begin()+id);
        break;
      }
      id++;
    }
    id=0;
    for(auto x:sp[v])
    {
      if(x[2]==rp)
      {
        sp[v].erase(sp[v].begin()+id);
        break;
      }
      id++;
    }
    for(int j=0;j<(int)spn.size();j++)
    {
      if(spn[j]==rp)
      {
        spn.erase(spn.begin()+j);
        break;
      }
    }
    spn.push_back(i);
    sp[ed[i][0]].push_back({ed[i][1],ed[i][2],i});
    sp[ed[i][1]].push_back({ed[i][0],ed[i][2],i});
    cnt[tr]++;cnt[tr^1]--;
  }
  if(cnt[0]!=cnt[1])no();
  cout<<n-1<<" ";
  for(auto x:spn)cout<<x<<" ";cout<<endl;
  return 0;
}