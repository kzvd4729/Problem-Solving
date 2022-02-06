/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/21/2021 20:37                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 156 ms                                          memory_used: 15500 KB                             
*  problem: https://codeforces.com/contest/1516/problem/D
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
const int N=1e5,inf=1e9,mod=1e9+7;
 vector<int>fac[N+2];
  int vs[N+2];
void factorize()
{
  for(int i=2;i<=N;i++)
  {
    if(vs[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      vs[j]=1;fac[j].push_back(i);
    }
  }
}
  int valid[N+2],ls[N+2],a[N+2],sp[N+2][20+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   factorize();
   int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=N;i++)ls[i]=n+1;
   valid[n+1]=n+1;
  for(int i=n;i>=1;i--)
  {
    int mn=n+1;
    for(auto x:fac[a[i]])
    {
      mn=min(mn,ls[x]);
      ls[x]=i;
    }
    valid[i]=min(mn-1,valid[i+1]);
  }
   //for(int i=1;i<=n;i++)cout<<valid[i]<<" ";cout<<endl;
   for(int i=0;i<=20;i++)sp[n+1][i]=n+1;
  for(int i=n;i>=1;i--)
  {
    sp[i][0]=valid[i];
    for(int j=1;j<=20;j++)
    {
      if(sp[i][j-1]<=n)sp[i][j]=sp[sp[i][j-1]+1][j-1];
      else sp[i][j]=n+1;
    }
  }
   while(q--)
  {
    int l,r;cin>>l>>r;
     //cout<<l<<" ** "<<r<<endl;
     int ans=0;
    while(true)
    {
      if(sp[l][0]>=r)
      {
        ans++;break;
      }
      for(int j=20;j>=0;j--)
      {
        if(sp[l][j]<r)
        {
          ans+=(1<<j);
          l=sp[l][j]+1;break;
        }
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}