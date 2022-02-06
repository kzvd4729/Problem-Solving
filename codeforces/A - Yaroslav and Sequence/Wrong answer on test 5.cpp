/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/06/2018 19:41                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/301/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int mx=-1e9,sum=0,ng=0,zr=0;
  for(int i=1;i<n+n;i++)
  {
    cin>>aa[i];sum+=abs(aa[i]);
    if(aa[i]==zr)zr++;
    if(aa[i]<0)
    {
      mx=max(mx,aa[i]);
      ng++;
    }
  }
  if(ng%2&&!zr)sum+=mx+mx;
  cout<<sum<<endl;
  return 0;
}