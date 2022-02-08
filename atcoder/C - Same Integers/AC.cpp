/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-07 18:04:45                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 36 ms                                           memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/arc094/tasks/arc094_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int a,b,c;
void srt()
{
  if(b<a)swap(a,b);
  if(c<a)swap(a,c);
  if(c<b)swap(b,c);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b>>c;
   for(int i=0; ;i++)
  {
    srt();
    if(a==b&&b==c)cout<<i<<endl,exit(0);
    if(b<c)a++,b++;
    else a+=2;
  }
  return 0;
}