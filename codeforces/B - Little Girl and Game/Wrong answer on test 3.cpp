/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/01/2018 22:42                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/276/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
int cnt[52],ans;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;
  for(auto x:s)
    cnt[x-'a']^=1;
  for(int i=0;i<26;i++)
    if(cnt[i])ans++;
  if(ans%2)cout<<"First"<<endl;
  else cout<<"Second"<<endl;
  return 0;
}