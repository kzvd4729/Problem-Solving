/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/07/2018 23:35                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1033/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e3;
bool prime(long x)
{
  if(x==1)return false;
  if(x==2)return true;
  if(x==3)return true;
  for(long i=2;i<=sqrt(x+1);i++)
    if(x%i==0)return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long a,b;cin>>a>>b;
    if(a-b==1&&prime(a+b))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}