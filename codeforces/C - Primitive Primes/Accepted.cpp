/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2020 21:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 561 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1316/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,p;cin>>n>>m>>p;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=m;i++)cin>>bb[i];
  int a,b;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]%p){a=i;break;}
  }
  for(int i=1;i<=m;i++)
  {
    if(bb[i]%p){b=i;break;}
  }
  cout<<a+b-2<<endl;
  return 0;
}