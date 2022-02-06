/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/28/2020 18:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 8200 KB                              
*  problem: https://codeforces.com/contest/519/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=0;i<26;i++)cin>>aa[i];
   string s;cin>>s;
  long bl=0,ans=0;
  for(int i=0;i<26;i++)
  {
    map<long,int>mp;
    for(auto x:s)
    {
      if(x-'a'==i)
      {
        ans+=mp[bl];bl+=aa[i];
        mp[bl]++;
      }
      else bl+=aa[x-'a'];
    }
  }
  cout<<ans<<endl;
  return 0;
}