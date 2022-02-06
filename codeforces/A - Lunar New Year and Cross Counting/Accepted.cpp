/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/09/2019 09:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/1106/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=500;
char mt[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=n;j++)
    {
      mt[i][j]=s[j-1];
    }
  }
  int ans=0;
  for(int i=2;i<n;i++)
  {
    for(int j=2;j<n;j++)
    {
      int x=1;
      if(mt[i][j]=='.')x=0;
      if(mt[i-1][j-1]=='.')x=0;
      if(mt[i-1][j+1]=='.')x=0;
      if(mt[i+1][j-1]=='.')x=0;
      if(mt[i+1][j+1]=='.')x=0;
      ans+=x;
    }
  }
  cout<<ans<<endl;
  return 0;
}