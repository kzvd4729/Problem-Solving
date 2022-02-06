/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/07/2018 23:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 1300 KB                              
*  problem: https://codeforces.com/contest/1033/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2],pos[N+2],gr[N+2];
char ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];pos[aa[i]]=i;
  }
  for(int i=n;i>=1;i--)
  {
    for(int j=pos[i]+i;j<=n;j+=i)
    {
      if(aa[j]>i)gr[i]|=gr[aa[j]]^1;
    }
    for(int j=pos[i]-i;j>=1;j-=i)
    {
      if(aa[j]>i)gr[i]|=gr[aa[j]]^1;
    }
  }
  for(int i=1;i<=n;i++)
  {
    if(gr[i]==0)
      ans[pos[i]]='B';
    else ans[pos[i]]='A';
  }
  for(int i=1;i<=n;i++)
    cout<<ans[i];
  cout<<endl;
  return 0;
}