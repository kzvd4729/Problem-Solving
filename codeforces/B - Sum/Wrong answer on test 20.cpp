/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/25/2018 00:56                        
*  solution_verdict: Wrong answer on test 20                 language: GNU C++17                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/49/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   int a,b;
  cin>>a>>b;
   int c=a;
   int mx=0;
  while(c)
  {
    mx=max(mx,c%10);
    c/=10;
  }
  c=b;
  while(c)
  {
    mx=max(mx,c%10);
    c/=10;
  }
  mx++;
  int ans=0;
   c=0;
  while(true)
  {
    int s=a%10+b%10+c;
    if(s==0)break;
    c=s/mx;
    a/=10;
    b/=10;
    ans++;
  }
  cout<<ans<<endl;
   return 0;
}