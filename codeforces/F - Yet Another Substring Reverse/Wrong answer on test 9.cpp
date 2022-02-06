/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/07/2019 20:11                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1234/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
int lo[N+2],hi[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int n=s.size();
  int ans=0;
  for(int i=0;i<s.size();i++)
  {
    int msk=0;
    for(int j=i;j<s.size();j++)
    {
      int c=s[j]-'a';if(msk&(1<<c))break;
      msk|=(1<<c);if(!lo[msk])lo[msk]=i+1;
      hi[msk]=i+1;
    }
    ans=max(ans,__builtin_popcount(msk));
  }
  for(int i=0;i<(1<<20);i++)
  {
    if(!lo[i])continue;
    int msk=(1<<20)-1-i;
    for(int sub=msk;sub>0;sub=(sub-1)&msk)
    {
      if(__builtin_popcount(i)+__builtin_popcount(sub)<=ans)break;
      if(lo[i]+__builtin_popcount(i)<=hi[sub])
        ans=__builtin_popcount(i)+__builtin_popcount(sub);
    }
  }
  cout<<ans<<endl;
  return 0;
}