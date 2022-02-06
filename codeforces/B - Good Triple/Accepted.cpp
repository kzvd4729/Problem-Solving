/****************************************************************************************
*  @author: kzvd4729                                         created: May/29/2019 19:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 16700 KB                             
*  problem: https://codeforces.com/contest/1168/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int nx[2][N+2],aa[N+2],mn[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int n=s.size();
  nx[0][n]=n;nx[1][n]=n;
  for(int i=n-1;i>=0;i--)
  {
    nx[0][i]=nx[0][i+1];
    nx[1][i]=nx[1][i+1];
    if(s[i]=='1')nx[1][i]=i;
    else nx[0][i]=i;
  }
  for(int i=0;i<n;i++)
  {
    int c=s[i]-'0';aa[i]=n;
    int first=nx[c][i+1];
    while(true)
    {
      if(first==n)break;
      int second=first+first-i;
      if(second>=n)break;
      first=nx[c][first+1];
      if(s[second]!=s[i])continue;
      aa[i]=second;break;
    }
  }
  mn[n]=n;
  for(int i=n-1;i>=0;i--)
    mn[i]=min(mn[i+1],aa[i]);
  long ans=0;
  for(int i=0;i<n;i++)
    ans+=(n-mn[i])*1LL;
  cout<<ans<<endl;
  return 0;
}