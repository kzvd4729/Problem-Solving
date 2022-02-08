/****************************************************************************************
*  @author: kzvd4729                                         created: 26-02-2019 22:45:10                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.08 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/COLE2019/problems/CLBATH
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const double eps=1e-9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int v1,t1,v2,t2,v3,t3;cin>>v1>>t1>>v2>>t2>>v3>>t3;
    if(t3>t2||t3<t1)cout<<"NO\n";
    else if(t3==t1)
    {
      if(v1>=v3)cout<<"YES\n";
      else cout<<"NO\n";
    }
    else if(t3==t2)
    {
      if(v2>=v3)cout<<"YES\n";
      else cout<<"NO\n";
    }
    else
    {
      int r1=t3-t1,r2=t2-t3;
      double lo=0,hi=v1,md,xx;int lop=120;
      while(lop--)
      {
        md=(lo+hi)/2.0;
        xx=((r1*1.0)/(r2*1.0))*md;
        if(xx>v2*1.0)hi=md;
        else lo=md;
      }
      if(md+xx+eps>=v3*1.0)cout<<"YES\n";
      else cout<<"NO\n";
    }
  }
  return 0;
}