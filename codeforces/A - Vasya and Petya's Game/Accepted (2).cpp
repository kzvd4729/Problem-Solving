/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2018 12:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
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
  int n,cnt=0,ans[1004];cin>>n;
  for(int i=2;i<=n;i++)
  {
    if(is_prime(i))
    {
      ans[++cnt]=i;
      int pw=i*i;
      while(pw<=n)
      {
        ans[++cnt]=pw;
        pw*=i;
      }
    }
  }
  cout<<cnt<<endl;
  for(int i=1;i<=cnt;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}