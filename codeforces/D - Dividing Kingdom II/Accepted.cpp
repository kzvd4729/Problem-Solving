/****************************************************************************************
*  @author: kzvd4729                                         created: May/06/2020 19:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 3805 ms                                         memory_used: 41300 KB                             
*  problem: https://codeforces.com/contest/687/problem/D
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
#include<unordered_map>
#define long long long
using namespace std;
const int N=1e6,R=1e9;
pair<int,int>par[N+2];
pair<int,int>find(int x)
{
  if(x!=par[x].first)
  {
    int pr=par[x].second;par[x]=find(par[x].first);
    par[x].second^=pr;
  }
  return par[x];
}
bool add(int a,int b)
{
  pair<int,int>pa=find(a),pb=find(b);
  if(pa.first==pb.first)return pa.second!=pb.second;
  par[pb.first]={pa.first,pa.second^pb.second^1};
  return true;
}
int aa[N+2],bb[N+2],cc[N+2],dd[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,q;cin>>n>>m>>q;vector<vector<int> >ed(m);
  for(int i=0;i<m;i++)
  {
    ed[i].resize(4);
    cin>>ed[i][1]>>ed[i][2]>>ed[i][0];ed[i][3]=i+1;
  }
  sort(ed.begin(),ed.end(),[&](vector<int>a,vector<int>b){
    return a[0]>b[0];
  });
  for(int i=0;i<ed.size();i++)
    aa[i+1]=ed[i][1],bb[i+1]=ed[i][2],cc[i+1]=ed[i][0],dd[i+1]=ed[i][3];
  while(q--)
  {
    int l,r,f=0;cin>>l>>r;
    for(int i=1;i<=n;i++)par[i]={i,0};
    for(int i=1;i<=m;i++)
    {
      if(dd[i]<l||dd[i]>r)continue;
      if(!add(aa[i],bb[i])){cout<<cc[i]<<"\n";f=1;break;}
    }
    if(!f)cout<<-1<<"\n";
  }
  return 0;
}