/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/29/2018 19:44                        
*  solution_verdict: Runtime error on test 18                language: GNU C++11                               
*  run_time: 452 ms                                          memory_used: 6200 KB                              
*  problem: https://codeforces.com/contest/967/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const double eps=0.000000001;
int n;
double a,b,xx,x,first,tt,tmp[100005],ttt;
priority_queue<double>pq;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>a>>b;
   for(int i=1;i<=n;i++)
  {
    cin>>x;
    tt+=x;
    if(i==1)first=x;
    else pq.push(x);
  }
  tmp[1]=pq.top();
  pq.pop();
  for(int i=2;i<n;i++)
  {
    tmp[i]=tmp[i-1]+pq.top();
    pq.pop();
  }
  int lo=0,hi=n-1;
  while(hi-lo>3)
  {
    int md=(lo+hi)/2;
    ttt=tt-tmp[md];
    double xx=(a*first)/ttt;
    if(xx>=b)hi=md;
    else lo=md;
  }
  for(int i=lo;i<=hi;i++)
  {
    ttt=tt-tmp[i];
    double xx=(a*first)/ttt;
    if((xx+eps)>=b)
    {
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<0<<endl;
  return 0;
}