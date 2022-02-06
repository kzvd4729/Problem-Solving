/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/23/2018 22:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/955/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long hh,mm,h,d,c,n,bun;
double rb,rb2,per;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>hh>>mm;
  cin>>h>>d>>c>>n;
   bun=(h+n-1)/n;
   rb=bun*(c*1.0);
  if(hh>=20)
  {
    per=(rb*20)/100;
    cout<<setprecision(10)<<fixed<<rb-per<<endl;
    return 0;
  }
   h+=((20*60-hh*60-mm)*d);
   bun=(h+n-1)/n;
   rb2=bun*(c*1.0);
   per=(rb2*20)/100;
   rb2-=per;
   rb=min(rb,rb2);
   cout<<setprecision(10)<<fixed<<rb<<endl;
   return 0;
}