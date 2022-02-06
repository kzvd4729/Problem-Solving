/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/23/2020 11:06                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 1856 ms                                         memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/679/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
pair<long,long>solve(long x)
{
  long cnt=0,xx=x;
  for(long i=N;i>=1;i--)
  {
    if(i*i*i<=x)
      cnt++,x-=i*i*i,i++;
  }
  return {cnt,xx-x};
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long m;cin>>m;
  long a=-1,b=-1;
  for(long i=m-1000;i<=m;i++)
  {
    pair<long,long>p=solve(i);
    if(p.first>a)a=p.first,b=p.second;
    else if(a==p.first)b=max(b,p.second);
  }
  cout<<a<<" "<<b<<endl;
  return 0;
}