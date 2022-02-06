/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/22/2019 20:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1207/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int b,p,f;cin>>b>>p>>f;
    int h,c;cin>>h>>c;
     int ans=0;
    if(h>=c)
    {
      int hm=min(b/2,p);
      ans+=hm*h;b-=2*hm;
       int cb=min(b/2,f);
      ans+=cb*c;
      cout<<ans<<"\n";
    }
    else
    {
      int cb=min(b/2,f);
      ans+=cb*c;b-=cb*2;
       int hm=min(b/2,p);
      ans+=hm*h;
      cout<<ans<<"\n";
    }
  }
  return 0;
}