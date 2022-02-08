/****************************************************************************************
*  @author: kzvd4729                                         created: 09-04-2021 03:17:25                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 1.89 sec                                        memory_used: 114.1M                               
*  problem: https://www.codechef.com/APRIL21A/problems/TREEPERM
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
vector<int>ad[N+2],an[N+2];
int a[N+2],b[N+2],pw[N+2],ls[N+2],lv[N+2],par[N+2],ent[N+2],ext[N+2],tim;
set<vector<int> >st;
void dfs(int nd,int pr,int hs,int l)
{
  ent[nd]=++tim;
  st.insert({hs,l,nd}); int er=hs; lv[nd]=l; par[nd]=pr;
  hs+=pw[a[nd]]-pw[b[nd]];
  hs%=mod;hs=(hs+mod)%mod;
  auto it=st.lower_bound({hs+1,-1,-1});
  if(it!=st.begin())
  {
    it--;vector<int>v=*it;
    if(v[0]==hs)ls[nd]=v[2];
  }
  for(auto x:ad[nd])if(x!=pr)dfs(x,nd,hs,l+1);
  st.erase({er,lv[nd],nd});
  ext[nd]=tim;
}
int vs[N+2],dp[N+2];
void rec(int nd,int pr)
{
  for(auto x:ad[nd])if(x!=pr)rec(x,nd);
  dp[nd]=0;
  if((int)an[nd].size()==0)return ;
  int ml=1,star=an[nd][0]; if((int)an[nd].size()>1)assert(0);
  if(star==nd)
  {
    int ch=0;
    for(auto x:ad[nd])
    {
      if(x==pr)continue;
      ml=(1LL*ml*dp[x])%mod;ch++;
    }
    dp[nd]=(1LL*(ch+1)*ml)%mod;
    return ;
  }
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    if(ent[star]>=ent[x] && ent[star]<=ext[x])continue;
    ml=(1LL*ml*dp[x])%mod;
  }
  int ch=0;
  for(auto x:ad[star])
  {
    if(x==par[star])continue;
    ch++;ml=(1LL*ml*dp[x])%mod;
  }
  dp[nd]=(1LL*(ch+1)*ml)%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]=1;
  for(int i=1;i<=N;i++)pw[i]=(1LL*pw[i-1]*10000019)%mod;
  int t;cin>>t;
  while(t--)
  {
    int n,s;cin>>n>>s;tim=0;
    for(int i=1;i<=n;i++)ad[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      ad[u].push_back(v);ad[v].push_back(u);
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    st.clear();for(int i=1;i<=n;i++)ls[i]=-1;
    dfs(1,-1,0,1);
    //for(int i=1;i<=n;i++)cout<<i<<" "<<ls[i]<<endl;
    vector<int>v;for(int i=1;i<=n;i++)v.push_back(i);
    sort(v.begin(),v.end(),[&](int a,int b){
      return lv[a]>lv[b];
    });
    for(int i=1;i<=n;i++)vs[i]=0;int f=1;
    for(int i=1;i<=n;i++)an[i].clear();
    for(auto x:v)
    {
      if(vs[x])continue;
      if(ls[x]==-1){f=0;break;}
      an[ls[x]].push_back(x);
      int nd=x;
      while(true)
      {
        if(vs[nd]){f=0;break;}
        vs[nd]=1;
        if(nd==ls[x])break;
        nd=par[nd];
      }
      if(f==0)break;
    }
    for(int i=1;i<=n;i++)dp[i]=0;
    if(f==0)cout<<0<<'\n';
    else
    {
      rec(1,-1);
      if(s==1)dp[1]=(bool)dp[1];
      if(dp[1]==0)assert(0);
      cout<<dp[1]<<'\n';
    }
  }
  return 0;
}