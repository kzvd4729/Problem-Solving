/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/19/2019 20:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/1118/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],cc[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];
    bb[i]=bb[i-1];cc[i]=cc[i-1];
    if(i%2)bb[i]+=aa[i];
    else cc[i]+=aa[i];
  }
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    int od=bb[i-1]+cc[n]-cc[i];
    int ev=cc[i-1]+bb[n]-bb[i];
    if(od==ev)ans++;
  }
  cout<<ans<<endl;
  return 0;
}