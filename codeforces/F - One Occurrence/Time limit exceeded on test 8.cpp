/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/26/2020 13:10                        
*  solution_verdict: Time limit exceeded on test 8           language: GNU C++17                               
*  run_time: 3000 ms                                         memory_used: 298100 KB                            
*  problem: https://codeforces.com/contest/1000/problem/F
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
int a[N+2];
set<pair<int,int> >sg[4*N+8];
void add(int nd,int lo,int hi,int id,pair<int,int>vl)
{
  sg[nd].insert(vl);if(lo==hi)return ;
  int md=(lo+hi)/2;
  if(id<=md)add(nd*2,lo,md,id,vl);
  else add(nd*2+1,md+1,hi,id,vl);
}
int ans[N+2];
void get(int nd,int lo,int hi,int lt,int rt,int l,int r,int v)
{
  if(lo>rt||hi<lt||sg[nd].size()==0)return ;
  if(lo>=lt&&hi<=rt)
  {
    auto it=sg[nd].lower_bound({l,-1});
    vector<pair<int,int> >buf;
    while(it!=sg[nd].end())
    {
      if(it->first>r)break;ans[it->second]=v;
      buf.push_back(*it);it++;
    }
    for(auto x:buf)sg[nd].erase(x);
    return ;
  }
  int md=(lo+hi)/2;
  get(nd*2,lo,md,lt,rt,l,r,v);
  get(nd*2+1,md+1,hi,lt,rt,l,r,v);
}
vector<int>po[N+2];
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
  for(int i=1;i<=N;i++)po[i].push_back(0);
  for(int i=1;i<=n;i++)cin>>a[i],po[a[i]].push_back(i);
  for(int i=1;i<=N;i++)po[i].push_back(n+1);
    int q;cin>>q;
  for(int i=1;i<=q;i++)
  {
    int l,r;cin>>l>>r;
    add(1,1,n,l,{r,i});
  }
   for(int i=1;i<=N;i++)
  {
    for(int j=1;j<po[i].size()-1;j++)
      get(1,1,n,po[i][j-1]+1,po[i][j],po[i][j],po[i][j+1]-1,i);
  }
  for(int i=1;i<=q;i++)cout<<ans[i]<<" ";cout<<endl;
  return 0;
}