/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/27/2020 17:52                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/817/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int sum(long x)
{
  int ret=0;
  while(x){ret+=x%10;x/=10;}
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,s;cin>>n>>s;
   int cnt=0;
  for(long i=s;i<=n;i++)
  {
    if(i-sum(i)<s)cnt++;
    if(clock()>CLOCKS_PER_SEC*0.8)break;
  }
  cout<<n-s+1-cnt<<endl;
  return 0;
}