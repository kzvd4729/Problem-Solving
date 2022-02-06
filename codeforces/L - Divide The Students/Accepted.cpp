/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/27/2019 17:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1250/problem/L
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e3;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int a,b,c;cin>>a>>b>>c;int ans=1e9;
    for(int i=0;i<=N;i++)
    {
      for(int j=0;j<=N;j++)
      {
        int as=i,cp=j,bs=b;
        if(as>a)bs-=(as-a);if(cp>c)bs-=(cp-c);
        if(bs<0)continue;
         if(as<a&&cp<c)continue;
        if(as<a)bs+=(a-as);
        if(cp<c)bs+=(c-cp);
         ans=min(ans,max(as,max(bs,cp)));
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}