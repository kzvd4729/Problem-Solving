/****************************************************************************************
*  @author: kzvd4729                                         created: 09-03-2021 23:06:18                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.01 sec                                        memory_used: 53M                                  
*  problem: https://www.codechef.com/MARCH21A/problems/MAXTOPO
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
const int N=1e6,inf=1e9,mod=1e9+7;
int fac[N+2],sub[N+2];
long tp[N+2];
vector<int>ad[N+2];
int ncr(int n,int r)
{
  return fac[n]/fac[r]/fac[n-r];
}
void dfs(int nd,int pr)
{
  sub[nd]=0,tp[nd]=1;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    dfs(x,nd);
    tp[nd]=tp[nd]*tp[x]*ncr(sub[x]+sub[nd],sub[x]);
    sub[nd]+=sub[x];
  }
  sub[nd]++;
} 
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  fac[0]=1;
  for(int i=1;i<=10;i++)fac[i]=fac[i-1]*i;
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    if(n>10)return 0;
    for(int i=1;i<=n;i++)ad[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      ad[u].push_back(v);ad[v].push_back(u);
    }
    vector<pair<long,int> >v;
    for(int i=1;i<=n;i++)
    {
      dfs(i,-1);
      v.push_back({tp[i]%mod,i});
    }
    sort(v.begin(),v.end(),[&](pair<long,int>a,pair<long,int>b){
      if(a.first==b.first)return a.second>b.second;
      return a.first>b.first;
    });
    //for(auto x:v)cout<<x.first<<" "<<x.second<<endl;
    cout<<v[k-1].second<<" "<<v[k-1].first%mod<<endl;
  }
  return 0;
}