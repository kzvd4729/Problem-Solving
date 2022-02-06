/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/29/2019 14:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 24000 KB                             
*  problem: https://codeforces.com/gym/102001/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
string s[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=0;i<n;i++)
    cin>>s[i];
   int ans=0;
  if(n==1)
  {
    for(int j=1;j<m-1;j++)
      ans+=s[0][j]=='.';
    cout<<ans<<endl,exit(0);
  }
  if(m==1)
  {
    for(int i=1;i<n-1;i++)
      ans+=s[i][0]=='.';
    cout<<ans<<endl,exit(0);
  }
  if(n==2)
  {
    for(int j=1;j<m-1;j++)
      ans+=(s[0][j]=='.'&&s[1][j]=='.');
    cout<<ans<<endl,exit(0);
  }
  if(m==2)
  {
    for(int i=1;i<n-1;i++)
      ans+=(s[i][0]=='.'&&s[i][1]=='.');
    cout<<ans<<endl,exit(0);
  }
  for(int i=1;i<n-1;i++)
  {
    for(int j=1;j<m-1;j++)
      ans+=s[i][j]=='.';
  }
  int f=1;
  for(int j=1;j<m-1;j++)
    f&=(!(s[0][j]=='#'));
  for(int j=1;j<m-1;j++)
    f&=(!(s[n-1][j]=='#'));
  for(int i=1;i<n-1;i++)
    f&=(!(s[i][0]=='#'));
  for(int i=1;i<n-1;i++)
    f&=(!(s[i][m-1]=='#'));
  cout<<ans+f<<endl;
    return 0;
}