/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/25/2020 14:03                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/585/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e3;
int v[N+2],d[N+2],p[N+2],vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<int>ans={1};
  for(int i=1;i<=n;i++)cin>>v[i]>>d[i]>>p[i];
   for(int i=2;i<=n;i++)
  {
    int pr=v[i-1];if(p[i-1]==-1)pr=-1;
    for(int j=i;j<=n;j++)
    {
      if(pr<=0)break;
      p[j]-=pr;if(p[j]<0)p[j]=-1;
      pr--;
    }
    if(p[i]<0)
    {
      for(int j=i+1;j<=n;j++)
      {
        p[j]-=d[i];if(p[j]<0)p[j]=-1;
      } 
    }
    else ans.push_back(i);
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)cout<<x<<" ";cout<<endl;
  return 0;
}