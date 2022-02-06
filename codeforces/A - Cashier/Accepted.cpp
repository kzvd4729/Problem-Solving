/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/06/2018 17:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/1059/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int ent[N+2],ext[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,l,a;cin>>n>>l>>a;l--;
  for(int i=1;i<=n;i++)
  {
    cin>>ent[i]>>ext[i];
    ext[i]+=ent[i]-1;
  }
  ext[0]=-1;ent[n+1]=l+1;
  int ans=0;
  for(int i=1;i<=n+1;i++)
  {
    ans+=(ent[i]-ext[i-1]-1)/a;
  }
  cout<<ans<<endl;
  return 0;
}