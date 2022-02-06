/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/12/2020 11:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1332/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int cnt[26+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;string s;cin>>s;int ans=0;
    for(int i=0;i<(k+1)/2;i++)
    {
      memset(cnt,0,sizeof(cnt));
      for(int j=i;j<n;j+=k)cnt[s[j]-'a']++;
      if(k-1-i!=i)
        for(int j=k-1-i;j<n;j+=k)cnt[s[j]-'a']++;
       int mx=0;
      for(int j=0;j<26;j++)
        ans+=cnt[j],mx=max(mx,cnt[j]);
      ans-=mx;
    }
    cout<<ans<<"\n";
  }
  return 0;
}