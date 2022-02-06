/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2021 14:51                        
*  solution_verdict: Time limit exceeded on test 6           language: GNU C++17 (64)                          
*  run_time: 1000 ms                                         memory_used: 5000 KB                              
*  problem: https://codeforces.com/contest/1552/problem/E
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
const int N=1e4,inf=1e9,mod=998244353;
  /* range add min max query */
int lz[4*N+8],mx[4*N+8];
void tooLazy(int nd,int lo,int hi)
{
  mx[nd]+=lz[nd];
  if(lo!=hi)lz[nd*2]+=lz[nd],lz[nd*2+1]+=lz[nd];
  lz[nd]=0;
}
void upd(int nd,int lo,int hi,int lt,int rt,int ad)
{
  tooLazy(nd,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lz[nd]+=ad;tooLazy(nd,lo,hi);return ;
  }
  int md=(lo+hi)/2;
  upd(nd*2,lo,md,lt,rt,ad);upd(nd*2+1,md+1,hi,lt,rt,ad);
  mx[nd]=max(mx[nd*2],mx[nd*2+1]);
}
  int n,k,a[N+2],ls[N+2],alw;
vector<pair<int,int> >v[N+2];
vector<pair<int,int> >ans;
 void dfs(int i)
{
  if(i>n)
  {
    for(auto x:ans)cout<<x.first<<" "<<x.second<<endl;
    exit(0);
  }
   for(auto p:v[i])
  {
    upd(1,1,n*k,p.first,p.second,1);
    if(mx[1]<=alw)
    {
      ans.push_back(p);
      dfs(i+1);
      ans.pop_back();
    }
     upd(1,1,n*k,p.first,p.second,-1);
  }
}
 int main()              
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n*k;i++)cin>>a[i];
   for(int i=1;i<=n;i++)ls[i]=-1;
   for(int i=1;i<=n*k;i++)
  {
    int x=a[i];
    if(ls[x]!=-1)v[x].push_back({ls[x],i});
     ls[x]=i;
  }
   //for(int i=1;i<=n;i++)shuffle(v[i].begin(),v[i].end(),rng);
  for(int i=1;i<=n;i++)
  {
    sort(v[i].begin(),v[i].end(),[&](pair<int,int>a,pair<int,int>b){
      return a.second<b.second;
    });
  }
   alw=(n+k-2)/(k-1);
  dfs(1);
    return 0;
}