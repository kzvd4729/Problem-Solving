/****************************************************************************************
*  @author: kzvd4729                                         created: 26-02-2019 22:17:04                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
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
    //if(0)cout<<"NO\n";
    else
    {
      double lo=0,hi=v2,md1,md2,mx=0;int lop=20;
      while(lop--)
      {
        md1=(lo+lo+hi)/3.0;
        md2=(lo+hi+hi)/3.0;
        double v11=(md1*t2-t3*md1)/((t3-t1)*1.0);
        double v12=(md2*t2-t3*md2)/((t3-t1)*1.0);
        v11=max(v11,v1*1.0);
        v12=max(v12,v1*1.0);
        if(v11+md1>=v12+md2)
          hi=md2;
        else lo=md1;
        mx=max(mx,v11+md1);
        mx=max(mx,v12+md2);
      }
      if(mx+eps>=(v3*1.0))cout<<"YES\n";
      else cout<<"NO\n";
    }
  }
  return 0;
}