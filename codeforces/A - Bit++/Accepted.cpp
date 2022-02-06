/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/20/2018 20:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/282/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  int ans=0;
  while(n--)
  {
    string s;cin>>s;
    if(s[0]=='+'||s[1]=='+')ans++;
    else ans--;
  }
  cout<<ans<<endl;
  return 0;
}