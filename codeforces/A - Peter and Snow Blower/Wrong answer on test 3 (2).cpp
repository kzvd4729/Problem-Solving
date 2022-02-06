/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/07/2019 15:05                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 15800 KB                             
*  problem: https://codeforces.com/contest/613/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
double pi=acos(-1.0);
pair<double,double>pp[N+2];
double dis(double a,double b,double c,double d)
{
  return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;double x,y;cin>>x>>y;
  for(int i=1;i<=n;i++)
    cin>>pp[i].first>>pp[i].second;
  double mn=1e15,mx=0;
  for(int i=1;i<=n;i++)
  {
    mx=max(mx,dis(x,y,pp[i].first,pp[i].second));
    mn=min(mn,dis(x,y,pp[i].first,pp[i].second));
  }
  double ans=pi*mx*mx-pi*mn*mn;
  cout<<setprecision(10)<<fixed<<ans<<endl;
  return 0;
}