/****************************************************************************************
*  @author: kzvd4729                                         created: May/02/2020 19:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/1340/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int a[N+2],p[N+2];
void solve()
{
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    a[x]=i,p[i]=0;
  }
  p[n+1]=1;
  //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
  int nx=-1;
  for(int i=1;i<=n;i++)
  {
    //cout<<nx<<endl;
    if(nx==-1)
    {
      p[a[i]]=1;if(p[a[i]+1]==0)nx=a[i]+1;
    }
    else
    {
      //cout<<"*"<<p[a[i]]<<endl;
      if(a[i]!=nx){cout<<"NO\n";return ;}
      nx++;if(p[nx])nx=-1;
    }
  }
  cout<<"YES\n";
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