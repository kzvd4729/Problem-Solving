/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/10/2018 20:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1055/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2];
void yes()
{
  cout<<"YES"<<endl;
  exit(0);
}
void no()
{
  cout<<"NO"<<endl;exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,s;cin>>n>>s;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=1;i<=n;i++)
    cin>>bb[i];
  if(!aa[1])no();
  if(aa[s])yes();
  for(int i=s+1;i<=n;i++)
  {
    if(aa[i]&&bb[i]&&bb[s])yes();
  }
  no();
  return 0;
}