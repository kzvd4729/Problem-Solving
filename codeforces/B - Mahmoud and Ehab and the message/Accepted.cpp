/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2018 22:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 358 ms                                          memory_used: 20000 KB                             
*  problem: https://codeforces.com/contest/959/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,m,c[100005],arr[100005],mn,ans,x;
string str,s[100005];
map<string,long>mp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k>>m;
  for(int i=1;i<=n;i++)cin>>s[i];
  for(int i=1;i<=n;i++)cin>>c[i];
  for(int i=1;i<=n;i++)mp[s[i]]=c[i];
  while(k--)
  {
    cin>>x;
    mn=1e16;
    for(int i=1;i<=x;i++)
    {
      cin>>arr[i];
      mn=min(mn,mp[s[arr[i]]]);
    }
    for(int i=1;i<=x;i++)mp[s[arr[i]]]=mn;
  }
  while(m--)
  {
    cin>>str;
    ans+=mp[str];
  }
  cout<<ans<<endl;
  return 0;
}