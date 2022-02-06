/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 1200 KB                              
*  problem: https://codeforces.com/contest/52/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int row[N+2],col[N+2];
char aa[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=m;j++)
    {
      char x=s[j-1];aa[i][j]=x;
      if(x=='*')row[i]++,col[j]++;
    }
  }
  long ans=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(aa[i][j]=='.')continue;
      ans+=((row[i]-1)*1LL)*(col[j]-1);
    }
  }
  cout<<ans<<endl;
  return 0;
}