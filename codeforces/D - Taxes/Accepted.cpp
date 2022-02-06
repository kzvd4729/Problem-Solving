/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/20/2018 20:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/735/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
bool prime(int x)
{
  for(int i=2;i<=sqrt(x+1);i++)
    if(x%i==0)return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
   if(prime(n))cout<<1<<endl;
  else if(n%2==0)cout<<2<<endl;
  else if(prime(n-2))cout<<2<<endl;
  else cout<<3<<endl;
   return 0;
}