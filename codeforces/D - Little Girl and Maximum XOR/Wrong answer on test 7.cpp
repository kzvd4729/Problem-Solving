/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/01/2018 23:01                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 372 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/276/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
long lt,rt,ans;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>lt>>rt;
  for(long i=lt;i<=min(lt+10000,rt);i++)
  {
    for(long j=rt;j>=max(lt,rt-10000);j--)
    {
      ans=max(ans,i^j);
    }
  }
  cout<<ans<<endl;
  return 0;
}