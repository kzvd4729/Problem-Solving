/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/03/2020 13:26                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 5900 KB                              
*  problem: https://codeforces.com/contest/899/problem/E
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
#include<stack>
#define long long long
using namespace std;
const int N=2e5;
int lft[N+2],rgt[N+2],aa[N+1],sz[N+2],par[N+2];
int getPar(int x){if(x==par[x])return x;return par[x]=getPar(par[x]);}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   for(int i=1;i<=n;i++)
  {
    lft[i]=i-1,rgt[i]=i+1,par[i]=i,sz[i]=1;
  }
  for(int i=2;i<=n;i++)
  {
    if(aa[i]!=aa[i-1])continue;
    int p=getPar(i-1);sz[p]++,par[i]=p;
    lft[i]=lft[i-1];
  }
  for(int i=n-1;i>=1;i--)
  {
    if(aa[i]!=aa[i+1])continue;
    rgt[i]=rgt[i+1];
  }
  set<vector<int> >st;
  for(int i=1;i<=n;i=rgt[i])
  {
    int p=getPar(i);
    st.insert({-sz[p],lft[i],rgt[i]});
  }
  int ans=0;
  while(st.size())
  {
    vector<int>v=*st.begin();st.erase(v),ans++;
    if(v[1]==0||v[2]==n+1||aa[v[1]]!=aa[v[2]])continue;
     int a=getPar(v[1]);st.erase({-sz[a],lft[v[1]],rgt[v[1]]});
    int b=getPar(v[2]);st.erase({-sz[b],lft[v[2]],rgt[v[2]]});
    sz[b]+=sz[a],par[a]=b;
    rgt[v[1]]=rgt[v[2]];lft[v[2]]=lft[v[1]];
    st.insert({-sz[b],lft[v[1]],rgt[v[2]]});
  }
  cout<<ans<<endl;
  return 0;
}