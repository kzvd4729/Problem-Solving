/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-10 18:05:34                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10215
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cout<<setprecision(3)<<fixed;
  int n,m;
  while(cin>>n>>m)
  {
    double x=n,y=m;
    double lo=0,hi=min(x,y)/2.0,md1,md2;
    for(int i=1;i<=200;i++)
    {
      md1=(lo+lo+hi)/3.0,md2=(lo+hi+hi)/3.0;
      double one=md1*(x-md1-md1)*(y-md1-md1);
      double two=md2*(x-md2-md2)*(y-md2-md2);
      if(one>two)hi=md2;else lo=md1;
    }
    cout<<md1<<" ";
    cout<<"0.000 "<<(min(x,y)/2.0)<<endl;
  }
  return 0;
}