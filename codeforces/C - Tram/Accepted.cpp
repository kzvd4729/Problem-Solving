/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/10/2018 01:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/746/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int s,x1,x2,t1,t2,p,st;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s>>x1>>x2;
  cin>>t1>>t2;
  cin>>p>>st;
   int ans;
  if(x2>=x1)
  {
    ans=(x2-x1)*t2;
    if(st==1)
    {
      if(p<=x1)
        ans=min(ans,(x2-p)*t1);
      else ans=min(ans,(s-p+s+x2)*t1);
    }
    else ans=min(ans,(p+x2)*t1);
  }
  else
  {
    ans=(x1-x2)*t2;
    if(st==-1)
    {
      if(p>=x1)
        ans=min(ans,(p-x2)*t1);
      else ans=min(ans,(p+s+s-x2)*t1);
    }
    else ans=min(ans,(s-p+s-x2)*t1);
  }
  cout<<ans<<endl;
   return 0;
}