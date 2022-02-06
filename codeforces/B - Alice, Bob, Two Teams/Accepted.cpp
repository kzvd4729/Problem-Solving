/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/17/2019 15:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 25300 KB                             
*  problem: https://codeforces.com/contest/632/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long aa[N+2],bb[N+2],cc[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>cc[i];
  string s;cin>>s;
  for(int i=1;i<=n;i++)
  {
    aa[i]=aa[i-1];bb[i]=bb[i-1];
    if(s[i-1]=='A')aa[i]+=cc[i];
    else bb[i]+=cc[i];
  }
  long ans=bb[n];
  for(int i=1;i<=n;i++)
  {
    ans=max(ans,bb[n]-bb[i]+aa[i]);
    ans=max(ans,bb[i-1]+aa[n]-aa[i-1]);
  }
  cout<<ans<<endl;
  return 0;
}