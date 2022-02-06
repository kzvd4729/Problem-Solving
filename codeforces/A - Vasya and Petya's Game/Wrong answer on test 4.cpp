/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2018 12:39                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
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
      if(i*i<=n)cnt++;
    }
  }
  cout<<cnt<<endl;
  for(int i=2;i<=n;i++)
  {
    if(is_prime(i))
    {
      cout<<i<<" ";
      if(i*i<=n)cout<<i*i<<" ";
    }
  }
  cout<<endl;
  return 0;
}