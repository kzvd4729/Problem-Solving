/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/17/2020 18:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/gym/100803/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int a,b;cin>>a>>b;
    if(a<b)
    {
      for(int j=a+1;j<=b;j++)
        vis[j]=1;
    }
  }
  int ans=n+1;
  for(int i=1;i<=n;i++)
    ans+=vis[i]+vis[i];
  cout<<ans<<endl;
   return 0;
}