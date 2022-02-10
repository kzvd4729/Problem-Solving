/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-22 23:43:41                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 70                                         memory_used (MB): 15.4                            
*  problem: https://vjudge.net/problem/SPOJ-FCTRL
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,ans,fv,t;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n;
    fv=1;
    ans=0;
    for(int i=1; ;i++)
    {
      fv=fv*5;
      if(fv>n)break;
      ans+=n/fv;
    }
    cout<<ans<<endl;
  }
  return 0;
}