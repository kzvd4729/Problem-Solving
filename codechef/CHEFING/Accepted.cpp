/****************************************************************************************
*  @author: kzvd4729                                         created: 01-02-2019 15:31:22                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.10 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/FEB19B/problems/CHEFING
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<int>cnt(30,0);int ans=0;
    for(int i=1;i<=n;i++)
    {
      string s;cin>>s;sort(s.begin(),s.end());
      s.erase(unique(s.begin(),s.end()),s.end());
      for(auto x:s)cnt[x-'a']++;
    }
    for(int i=0;i<26;i++)
      if(cnt[i]==n)ans++;
    cout<<ans<<endl;
  }
  return 0;
}