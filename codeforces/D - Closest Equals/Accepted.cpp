/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/14/2020 13:35                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1855 ms                                         memory_used: 216100 KB                            
*  problem: https://codeforces.com/contest/522/problem/D
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
const int N=5e5;
pair<int,int>a[N+2];
vector<pair<int,int> >sg[4*N+8];
vector<int>mn[4*N+8];
void build(int nd,int lo,int hi)
{
  if(lo==hi)
  {
    sg[nd].push_back(a[lo]);
    mn[nd].push_back(a[lo].second);
    return;
  }
  int md=(lo+hi)/2;
  build(nd*2,lo,md);build(nd*2+1,md+1,hi);
   sg[nd].resize((int)sg[nd*2].size()+(int)sg[nd*2+1].size());
  merge(sg[nd*2].begin(),sg[nd*2].end(),sg[nd*2+1].begin(),sg[nd*2+1].end(),sg[nd].begin());
    mn[nd].resize((int)sg[nd].size());
  mn[nd][0]=sg[nd][0].second;
  for(int i=1;i<(int)sg[nd].size();i++)
    mn[nd][i]=min(mn[nd][i-1],sg[nd][i].second);
}
int get(int nd,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return N+2;
  if(lo>=lt&&hi<=rt)
  {
    int id=upper_bound(sg[nd].begin(),sg[nd].end(),make_pair(rt+1,-1))-sg[nd].begin();
    int ret=N+2;
    //cout<<mn[nd].size()<<" "<<id-1<<endl;
    if(id>0)ret=mn[nd][id-1];
    return ret;
  }
  int md=(lo+hi)/2;
  return min(get(nd*2,lo,md,lt,rt),get(nd*2+1,md+1,hi,lt,rt));
}
map<int,vector<int> >mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    mp[x].push_back(i);
  }
  for(int i=1;i<=n;i++)a[i]={n+1,0};
  for(auto x:mp)
  {
    vector<int>&v=x.second;
    for(int i=0;i<(int)v.size()-1;i++)
      a[v[i]]={v[i+1],v[i+1]-v[i]};
  }
  build(1,1,n);
  //for(int i=1;i<=n;i++)
    //cout<<a[i].first<<" --> "<<a[i].second<<endl;
  while(m--)
  {
    int l,r;cin>>l>>r;
    int ans=get(1,1,n,l,r);if(ans>N)ans=-1;
    cout<<ans<<" ";
  }
  cout<<endl;
  return 0;
}