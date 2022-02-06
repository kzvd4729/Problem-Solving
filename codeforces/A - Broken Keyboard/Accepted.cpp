/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/24/2019 21:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1251/problem/A
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
    string s,ans;cin>>s;int cnt=1;
    for(int i=1;i<s.size();i++)
    {
      if(s[i]==s[i-1])cnt++;
      else
      {
        if(cnt%2)ans.push_back(s[i-1]);
        cnt=1;
      }
    }
    if(cnt%2)ans.push_back(s.back());
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    cout<<ans<<"\n";
  }
  return 0;
}