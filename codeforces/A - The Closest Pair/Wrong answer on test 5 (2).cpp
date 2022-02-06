/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/15/2018 16:34                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/311/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
pair<double,double>p[N+2];
double dis(pair<double,double>p1,pair<double,double>p2)
{
  return sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;
  //cout<<(n*(n-1))/2<<endl;
  if(k>(n*(n-1))/2)cout<<"no solution"<<endl,exit(0);
   int x=0,y=-1000000000;
  for(int i=1;i<=n;i++)
  {
    p[i]={x,y};x++;y+=10000;
    cout<<x<<" "<<y<<endl;
  }
  // double d=1e14;int cnt=0;
  // for(int i=1;i<=n;i++)
  // {
  //   for(int j=i+1;j<=n;j++)
  //   {
  //     cnt++;
  //     if(p[j].first-p[i].first>=d)break;
  //     d=min(d,dis(p[i],p[j]));
  //   }
  // }
  // cout<<p[n].second<<endl;
  // cout<<cnt<<endl;
  return 0;
}