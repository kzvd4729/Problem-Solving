/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2018 12:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/576/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
bool is_prime(int x)
{
  for(int i=2;i<x;i++)
    if(x%i==0)return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,cnt=0;cin>>n;
  for(int i=2;i<=n;i++)
  {
    if(is_prime(i))
    {
      cnt++;
      int pw=i*i;
      while(pw<=n)
      {
        cnt++;
        pw*=i;
      }
    }
  }
  cout<<cnt<<endl;
  for(int i=2;i<=n;i++)
  {
    if(is_prime(i))
    {
      cout<<i<<" ";
      int pw=i*i;
      while(pw<=n)
      {
        cout<<pw<<" ";
        pw*=i;
      }
    }
  }
  cout<<endl;
  return 0;
}