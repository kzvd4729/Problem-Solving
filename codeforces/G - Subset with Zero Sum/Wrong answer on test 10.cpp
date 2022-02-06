/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/26/2020 17:20                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 560 ms                                          memory_used: 23300 KB                             
*  problem: https://codeforces.com/contest/1270/problem/G
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
#include<deque>
#define long long long  
using namespace std;
const int N=1e6;
int a[N+2],vs[N+2],b[N+2];
pair<int,int>pp[N+2];
map<int,int>mp;
void solve()
{
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i],vs[i]=0;
  for(int i=1;i<=n;i++)
  {
    if(a[i]==0){cout<<1<<"\n"<<i<<"\n";return;}
    if(a[i]>0)vs[a[i]]=i;
  }
  for(int i=1;i<=n;i++)
  {
    if(a[i]>0)continue;
    if(vs[-a[i]]){cout<<2<<"\n"<<i<<" "<<vs[-a[i]]<<"\n";return;}
  }
  for(int i=1;i<=n;i++)pp[i]={a[i],i};
  sort(pp+1,pp+n+1);int l=0,r=0,sm;vector<int>ans;
  for(int i=1;i<=n;i++)b[i]=pp[i].first;
  for(int i=1;i<n;i++)
    if(b[i]<0&&b[i+1]>0)l=i,r=i,sm=b[i],mp[b[i]]=i,ans.push_back(pp[i].second);
  while(true)
  {
    if(sm<0)
    {
      if(r==n)assert(0);
      r++;sm+=b[r],ans.push_back(pp[r].second);
      mp[b[r]]=r;
    }
    else
    {
      if(l==1)assert(0);
      l--;sm+=b[l],ans.push_back(pp[l].second);
      mp[b[l]]=l;
    }
    if(sm==0)
    {
      cout<<ans.size()<<"\n";
      for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";cout<<"\n";
      return;
    }
    if(mp[sm])
    {
      cout<<ans.size()-1<<"\n";
      for(int i=0;i<ans.size();i++)
      {
        if(a[ans[i]]==sm){sm=0;continue;}
        cout<<ans[i]<<" ";
      }
      cout<<"\n";return;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}