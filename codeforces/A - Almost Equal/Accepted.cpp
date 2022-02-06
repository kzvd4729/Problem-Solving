/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/20/2020 10:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1205/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  if(n%2==0)cout<<"NO\n",exit(0);
  cout<<"YES\n";
   int sw=0,cnt=0;
  for(int i=1;i<=n;i++)
  {
    aa[i]=++cnt;aa[i+n]=++cnt;
    if(sw)(swap(aa[i],aa[n+i]));
    sw^=1;
  }
  for(int i=1;i<=n+n;i++)cout<<aa[i]<<" ";cout<<endl;
  return 0;
}