/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/09/2020 10:35                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/1333/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<int>aa(n+2),bb(n+2);
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=n;i++)cin>>bb[i];
     int p=0,m=0,f=0;
    for(int i=1;i<=n;i++)
    {
      if(aa[i]==bb[i]);
      else if(bb[i]>aa[i]&&!p)f=1;
      else if(bb[i]<aa[i]&&!m)f=1;
       if(aa[i]==1)p=1;
      if(aa[i]==-1)m=1;
    }
    if(f)cout<<"NO\n";else cout<<"YES\n";
  }
  return 0;
}