/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/25/2018 19:44                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1029/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,c;
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 cin>>a>>b;c=a+b;vector<long>vv;
 for(long i=1;i<=sqrt(a+1);i++)
  if(a%i==0)vv.push_back(i);
 long ans=1e18;
 for(long i=1;i<=sqrt(c+1);i++)
 {
  if(c%i)continue;
  for(long j=0;j<vv.size();j++)
  {
   if(vv[j]<=i&&(a/vv[j])<=(c/i))
    ans=min(ans,2*(i+(c/i)));
  }
 }
 cout<<ans<<endl;
 return 0;
}