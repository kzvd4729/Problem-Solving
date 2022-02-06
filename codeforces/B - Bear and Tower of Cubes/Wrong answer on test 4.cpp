/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/23/2020 12:10                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/679/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
long m;
pair<long,long>solve(long x)
{
  if(x>m)return {-1,-1};
  long cnt=0,xx=x,mx=-1;
  for(long i=N;i>=1;i--)
  {
    if(i*i*i<=x)
    {
      if(mx==-1)mx=i;
      cnt++,x-=i*i*i,i++;
    }
  }
  xx-=x;
  for(long i=mx+1; ;i++)
  {
    if(i*i*i+xx>m)return {cnt,xx};
    cnt++;xx+=i*i*i;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>m;
  long a=-1,b=-1;
  for(long i=1;i<=200;i++)
  {
    pair<long,long>p=solve(i);
    if(p.first>a)a=p.first,b=p.second;
    else if(a==p.first)b=max(b,p.second);
  }
  cout<<a<<" "<<b<<endl;
  return 0;
}