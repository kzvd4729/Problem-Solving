/****************************************************************************************
*  @author: kzvd4729#                                        created: May/29/2020 18:12                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 78400 KB                             
*  problem: https://codeforces.com/contest/467/problem/E
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
#include<random>
#include<chrono>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],rm[N+2];
void compress(int n)
{
  vector<int>v;
  for(int i=1;i<=n;i++)v.push_back(aa[i]);
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   map<int,int>mp;
  for(int i=0;i<v.size();i++)mp[v[i]]=i+1,rm[i+1]=v[i];
   for(int i=1;i<=n;i++)aa[i]=mp[aa[i]];
}
int rt[N+2],ls[N+2],n;
vector<int>seg[4*N+2];
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node].push_back(rt[lo]);return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  seg[node].resize(seg[node*2].size()+seg[node*2+1].size());
  merge(seg[node*2].begin(),seg[node*2].end(),seg[node*2+1].begin(),seg[node*2+1].end(),seg[node].begin());
}
int get(int node,int lo,int hi,int lt,int rt,int k)
{
  if(lo>rt||hi<lt)return n+1;
  if(lo>=lt&&hi<=rt)
  {
    int id=upper_bound(seg[node].begin(),seg[node].end(),k)-seg[node].begin();
    if(id==seg[node].size())return n+1;
    else return seg[node][id];
  }
  int md=(lo+hi)/2;
  return min(get(node*2,lo,md,lt,rt,k),get(node*2+1,md+1,hi,lt,rt,k));
}
int dp[N+1];
vector<int>f[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  compress(n);
  for(int i=n;i>=1;i--)
  {
    rt[i]=ls[aa[i]];ls[aa[i]]=i;
    if(rt[i]==0)rt[i]=n+1;
  }
  build(1,1,n);
  for(int i=n;i>=1;i--)
  {
    dp[i]=dp[i+1];
    int j=rt[i];if(j==i+1)continue;
    int mn=get(1,1,n,i+1,j-1,j);
    if(mn<=n)
    {
      dp[i]=max(dp[i],dp[mn+1]+1);
      f[i].push_back(aa[i]);
      f[i].push_back(aa[mn]);
      f[i].push_back(mn);
    }
  }
  cout<<dp[1]*4<<endl;int pt=1,cnt=0;
  while(pt<=n)
  {
    if(dp[pt]==dp[pt+1])pt++;
    else
    {
      cout<<rm[f[pt][0]]<<" "<<rm[f[pt][1]]<<" "<<rm[f[pt][0]]<<" "<<rm[f[pt][1]]<<" ";
      cnt++;
      pt=f[pt][2]+1;
    }
  }
  if(cnt!=dp[1])assert(0);
  cout<<endl;
  return 0;
}