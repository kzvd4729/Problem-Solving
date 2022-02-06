/****************************************************************************************
*  @author: kzvd4729                                         created: May/02/2020 19:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1343/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int m=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;if(x==0)continue;
      aa[++m]=x;
    }
    n=m;long ans=0;
    for(int i=1;i<=n; )
    {
      int j,mx=-2e9;
      for(j=i;j<=n;j++)
      {
        if((aa[i]<0&&aa[j]<0)||(aa[i]>0&&aa[j]>0))
          mx=max(mx,aa[j]);
        else break;
      }
      ans+=mx;i=j;
    }
    cout<<ans<<"\n";
  }
  return 0;
}