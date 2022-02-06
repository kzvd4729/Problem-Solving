/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/04/2019 10:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/1045/problem/I
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;map<int,int>mp;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;int msk=0;
    for(auto x:s)
    {
      int c=x-'a';msk^=(1<<c);
    }
    mp[msk]++;//cout<<msk<<endl;
  }
  long ans=0;
  for(auto x:mp)
  {
    int msk=x.first;//cout<<msk<<endl;
    ans+=(1LL*mp[msk]*(mp[msk]-1))/2;
    for(int i=0;i<26;i++)
    {
      int r=(msk^(1<<i));
      if(mp.count(r))ans+=(1LL*mp[r]*mp[msk]);
    }
    mp[msk]=0;
  }
  cout<<ans<<endl;
  return 0;
}