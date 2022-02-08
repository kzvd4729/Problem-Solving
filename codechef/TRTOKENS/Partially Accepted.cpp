/****************************************************************************************
*  @author: kzvd4729                                         created: 01-06-2021 18:54:59                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.72 sec                                        memory_used: 61.2M                                
*  problem: https://www.codechef.com/problems/TRTOKENS
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
const int N=1e6,inf=1e9,mod=1000000007;
int p[N+2],lv[N+2];
vector<int>ad[N+2];string s;
void dfs(int nd,int pr,int l)
{
  lv[nd]=l;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    dfs(x,nd,l+1);
  }
}
int mx,dn;
void dfs3(int nd,int pr,int l)
{
  if(s[nd]=='1' && l>mx)mx=l,dn=nd;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    dfs3(x,nd,l+1);
  }
}
void dfs2(int nd,int pr)
{
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    dfs2(x,nd);
  }
  if(s[nd]=='1')return ;
  mx=-1;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    dfs3(x,nd,1);
  }
  if(mx==-1)return ;
  swap(s[nd],s[dn]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;cin>>s;s="#"+s;
    for(int i=1;i<=n;i++)ad[i].clear();
    for(int i=2;i<=n;i++)
    {
      cin>>p[i];
      ad[p[i]].push_back(i);
    }
    dfs(1,-1,0);
    long tt=0;
    for(int i=1;i<=n;i++)if(s[i]=='1')tt+=lv[i];
    dfs2(1,-1);
    for(int i=1;i<=n;i++)if(s[i]=='1')tt-=lv[i];
    cout<<tt<<endl;
  }
  return 0;
}