/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/12/2018 21:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/1076/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int fg[N+2];
double ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   for(int i=0;i<=1000;i++)
  {
    double x=i*1.0;
     double lo=0.0,hi=x/2.0,md;
     if(((hi*hi)+0.0000001)<x)fg[i]=1;
     int loop=100;
    while(loop--)
    {
      md=(lo+hi)/2.0;
      if((md*(x-md))>x)hi=md;
      else lo=md;
    }
    ans[i]=md;
  }
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    if(fg[n])cout<<"N"<<endl;
    else 
    {
      cout<<"Y ";
      cout<<setprecision(10)<<fixed<<(n*1.0)-ans[n]<<" "<<ans[n]<<endl;
     }
  }
  return 0;
}