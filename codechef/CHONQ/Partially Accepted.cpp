/****************************************************************************************
*  @author: kzvd4729                                         created: 01-03-2019 19:36:43                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 1.56 sec                                        memory_used: 15.3M                                
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
      int sm=0,f=0;
      for(int j=i;j<=n;j++)
      {
        sm+=aa[j]/(j-i+1);
        if(sm>k)
        {
          f=1;break;
        }
      }
      if(f==0)
      {
        cout<<i<<"\n";g=1;break;
      }
    }
    if(!g)cout<<n+1<<"\n";
  }
  return 0;
}