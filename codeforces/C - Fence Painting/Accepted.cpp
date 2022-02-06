/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/05/2021 21:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 40500 KB                             
*  problem: https://codeforces.com/contest/1481/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
int a[N+2],b[N+2],c[N+2],ans[N+2];
vector<int>mt[N+2],un[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=m;i++)cin>>c[i];
     for(int i=1;i<=n;i++)mt[i].clear(),un[i].clear();
    for(int i=1;i<=n;i++)
    {
      if(a[i]==b[i])mt[b[i]].push_back(i);
      else un[b[i]].push_back(i);
    }
    int pr=-1,f=0;
    for(int i=m;i>=1;i--)
    {
      if((int)un[c[i]].size())
      {
        ans[i]=un[c[i]].back();
        un[c[i]].pop_back();pr=ans[i];
      }
      else if((int)mt[c[i]].size())
      {
        ans[i]=mt[c[i]].back();
        pr=ans[i];
      }
      else if(pr!=-1)
      {
        ans[i]=pr;
      }
      else
      {
        f=1;break;
      }
    }
    for(int i=1;i<=n;i++)if((int)un[i].size())f=1;
    if(f)cout<<"NO\n";
    else
    {
      cout<<"YES\n";
      for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
      cout<<'\n';
    }
  }
  return 0;
}