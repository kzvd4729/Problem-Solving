/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/15/2020 19:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1304/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;int mn=m,mx=m;
    int ls=0,f=0;
    for(int i=1;i<=n;i++)
    {
      int a,b,c;cin>>a>>b>>c;
      mn=max(b,mn-(a-ls));
      mx=min(c,mx+(a-ls));
       if(mn>mx||mn>c||mx<b)f=1;
      ls=a;
      //cout<<mn<<" "<<mx<<endl;
    }
    if(f)cout<<"NO\n";else cout<<"YES\n";
  }
  return 0;
}