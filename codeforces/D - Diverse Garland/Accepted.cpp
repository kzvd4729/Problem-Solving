/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/23/2019 21:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1108/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n;string s;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;cin>>s;int ans=0;
  for(int i=1;i<n;i++)
  {
    if(s[i]==s[i-1])
    {
      ans++;
      if(i==n-1)
      {
        if(s[i-1]=='B')s[i]='G';
        else if(s[i-1]=='R')s[i]='G';
        else if(s[i-1]=='G')s[i]='R';
      }
      else
      {
        if(s[i-1]=='R'&&s[i+1]=='B')
          s[i]='G';
        else if(s[i-1]=='R'&&s[i+1]=='G')
          s[i]='B';
        else if(s[i-1]=='B'&&s[i+1]=='G')
          s[i]='R';
        else if(s[i-1]=='B'&&s[i+1]=='R')
          s[i]='G';
        else if(s[i-1]=='G'&&s[i+1]=='R')
          s[i]='B';
        else if(s[i-1]=='G'&&s[i+1]=='B')
          s[i]='R';
        else if(s[i-1]=='B'&&s[i+1]=='B')
          s[i]='G';
        else if(s[i-1]=='G'&&s[i+1]=='G')
          s[i]='B';
        else if(s[i-1]=='R'&&s[i+1]=='R')
          s[i]='B';
      }
    }
  }
  cout<<ans<<endl;
  cout<<s<<endl;
  return 0;
}