/****************************************************************************************
*  @author: * kzvd4729                                       created: Sep/21/2019 13:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1216/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;
  int ans=0;
  for(int i=0;i<s.size();i+=2)
  {
    if(s[i]==s[i+1])
    {
      ans++;
      if(s[i]=='a')s[i]='b';
      else s[i]='a';
    }
  }
  cout<<ans<<endl<<s<<endl;
  return 0;
}