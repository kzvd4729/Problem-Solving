/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/27/2018 15:40                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/999/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
int n,m,c,ans,in[N+2],out[N+2],u,v;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>c;
  while(m--)
  {
    cin>>u>>v;
    in[v]++;
    out[u]++;
  }
  for(int i=1;i<=n;i++)
  {
    if(i==c)continue;
    if(in[i]==0)ans++;
  }
  if(out[c]==0&&n>1)ans++;
  cout<<ans<<endl;
  return 0;
}