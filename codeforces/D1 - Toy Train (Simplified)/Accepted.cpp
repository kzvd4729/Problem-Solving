/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/24/2019 23:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1130/problem/D1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
vector<int>des[N+2];
int n;
struct data
{
  int lap,ex;
}aa[N+2];
int dis(int i,int j)
{
  if(j>=i)return j-i;
  return j-i+n;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    des[u].push_back(v);
  }
  for(int i=1;i<=n;i++)
  {
    if(des[i].size()==0)
    {
      aa[i]={0,0};continue;
    }
    int mn=1e9;
    for(auto x:des[i])
      mn=min(mn,dis(i,x));
    aa[i]={(int)des[i].size()-1,mn};
  }
  for(int i=1;i<=n;i++)
  {
    long ans=0;
    for(int j=1;j<=n;j++)
    {
      if(des[j].size()==0)continue;
      ans=max(ans,dis(i,j)*1LL+aa[j].lap*1LL*n+aa[j].ex);
    }
    cout<<ans<<" ";
  }
  cout<<endl;
  return 0;
}