/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2018 16:44                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/854/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n;
bool check(int a,int b)
{
  for(int i=2;i<=a;i++)
  {
    if(a%2==0&&b%i==0)return false;
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=n/2;i>=1;i--)
  {
    if(check(i,n-i))
    {
      cout<<i<<" "<<n-i<<endl;
      return 0;
    }
  }
  return 0;
}