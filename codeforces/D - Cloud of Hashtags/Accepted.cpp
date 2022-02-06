/****************************************************************************************
*  @author: kzvd4729                                         created: May/06/2020 13:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 13000 KB                             
*  problem: https://codeforces.com/contest/777/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
string s[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>s[i];
   for(int i=n-1;i>=1;i--)
  {
    for(int j=0;j<s[i].size();j++)
    {
      if(j==s[i+1].size()||s[i][j]>s[i+1][j])
      {
        s[i].erase(j,s[i].size()-j);
        break;
      }
      if(s[i][j]<s[i+1][j])break;
    }
  }
  for(int i=1;i<=n;i++)cout<<s[i]<<"\n";
  return 0;
}