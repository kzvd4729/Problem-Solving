/****************************************************************************************
*  @author: kzvd4729                                         created: 04-03-2019 16:12:52                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.05 sec                                        memory_used: 15.3M                                
*  problem: https://www.codechef.com/MARCH19A/problems/CHONQ
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie();
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;int g=0;
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=n;i++)
    {
      long sm=0,f=0;
      for(int j=i;j<=n;j++)
      {
        sm+=aa[j]/(j-i+1);
      }
      if(sm<=k)
      {
        cout<<i<<endl;
        g=1;break;
      }
    }
    if(!g)cout<<n+1<<endl;
  }
  return 0;
}