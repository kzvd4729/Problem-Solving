/****************************************************************************************
*  @author: kzvd4729                                         created: 20-01-2019 22:26:21                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.26 sec                                        memory_used: 22.9M                                
*  problem: https://www.codechef.com/COOK102A/problems/ADAMTR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=(1<<10);
int aa[N+2][N+2],bb[N+2][N+2],n;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        cin>>aa[i][j];
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        cin>>bb[i][j];
      }
    }
    int ok=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        if(aa[i][j]!=bb[i][j])
          swap(aa[i][j],aa[j][i]);
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        if(aa[i][j]!=bb[i][j])ok=1;
      }
    }
    if(ok)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
  }
  return 0;
}