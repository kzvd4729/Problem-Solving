/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/26/2018 15:01                        
*  solution_verdict: Wrong answer on test 26                 language: GNU C++11                               
*  run_time: 873 ms                                          memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/996/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,pos[N+2];
struct point
{
  double x,y;
}p[N+2];
double mag(point pp)
{
  return sqrt(pp.x*pp.x+pp.y*pp.y);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>p[i].x>>p[i].y;
  point pp={0,0},tm1,tm2;
  for(int i=1;i<=n;i++)
  {
    tm1={pp.x+p[i].x,pp.y+p[i].y};
    tm2={pp.x-p[i].x,pp.y-p[i].y};
    if(mag(tm1)<=mag(tm2))
    {
      pp=tm1;
      pos[i]=1;
    }
    else
    {
      pp=tm2;
      pos[i]=-1;
    }
  }
  for(int i=1;i<=n;i++)cout<<pos[i]<<" ";
  cout<<endl;
  return 0;
}