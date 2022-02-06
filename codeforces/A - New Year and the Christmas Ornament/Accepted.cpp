/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/01/2019 13:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1091/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int a,b,c;
bool ok(int i)
{
  if(i<=a&&(i+1)<=b&&(i+2)<=c)return true;
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>a>>b>>c;int ans=0;
   for(int i=1;i<=10000;i++)
  {
    if(ok(i))ans=max(ans,i+i+1+i+2);
  }
  cout<<ans<<endl;
   return 0;
}