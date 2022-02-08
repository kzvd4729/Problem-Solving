/****************************************************************************************
*  @author: kzvd4729                                         created: 09-04-2021 02:46:19                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 1.79 sec                                        memory_used: 79.8M                                
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
vector<int>ad[N+2];
int a[N+2],b[N+2],pw[N+2],ls[N+2],lv[N+2],par[N+2];
set<vector<int> >st;
void dfs(int nd,int pr,int hs,int l)
{
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
}
int vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]=1;
  for(int i=1;i<=N;i++)pw[i]=(1LL*pw[i-1]*10000019)%mod;
  int t;cin>>t;
  while(t--)
  {
    int n,s;cin>>n>>s;
    for(int i=1;i<=n;i++)ad[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      ad[u].push_back(v);ad[v].push_back(u);
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    st.clear();memset(ls,-1,sizeof ls);
    dfs(1,-1,0,1);
    //for(int i=1;i<=n;i++)cout<<i<<" "<<ls[i]<<endl;
    vector<int>v;for(int i=1;i<=n;i++)v.push_back(i);
    sort(v.begin(),v.end(),[&](int a,int b){
      return lv[a]>lv[b];
    });
    memset(vs,0,sizeof vs);int f=1;
    for(auto x:v)
    {
      if(vs[x])continue;
      if(ls[x]==-1){f=0;break;}
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
    cout<<f<<'\n';
  }
  return 0;
}