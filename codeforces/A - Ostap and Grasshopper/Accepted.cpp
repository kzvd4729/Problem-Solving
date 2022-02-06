/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/20/2018 19:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/735/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  string s;cin>>s;
  int f=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='G')
    {
      for(int j=i+k;j<n;j+=k)
      {
        if(s[j]=='T')f=1;
        else if(s[j]=='#')break;
      }
      for(int j=i-k;j>=0;j-=k)
      {
        if(s[j]=='T')f=1;
        else if(s[j]=='#')break;
      }
    }
  }
  if(f)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}