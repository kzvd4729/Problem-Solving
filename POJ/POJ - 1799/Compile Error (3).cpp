/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-30 00:55:59                      
*  solution_verdict: Compile Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-1799
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const double pi=acos(-1);
long t,tc;
double R,n,ans,ang;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>R>>n;
    ang=((2*pi)/n)/2.0;
    ans=(R*sin(ang))/(1.00+sin(ang));
    cout<<"Scenario #"<<++tc<<":"<<endl;
    cout<<setprecision(3)<<fixed<<ans<<endl<<endl;
  }
  return 0;
}