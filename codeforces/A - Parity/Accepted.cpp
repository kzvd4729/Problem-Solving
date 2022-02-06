/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1110/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int b,k;cin>>b>>k;
  for(int i=1;i<=k;i++)
    cin>>aa[i],aa[i]%=2;
   int bs=1;int sum=0;
  for(int i=k;i>=1;i--)
  {
    sum=(sum+aa[i]*bs)%2;
    bs=(bs*b)%2;
  }
  if(sum)cout<<"odd"<<endl;
  else cout<<"even"<<endl;
  return 0;
}