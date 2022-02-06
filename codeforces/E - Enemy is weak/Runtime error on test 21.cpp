/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2019 00:58                        
*  solution_verdict: Runtime error on test 21                language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 31300 KB                             
*  problem: https://codeforces.com/contest/61/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long aa[N+2],bit[3][N+2];
void upd(int id,int x,long vl)
{
  for( ;x<=N;x+=x&-x)
    bit[id][x]+=vl;
}
long get(int id,int x)
{
  long sm=0;
  for( ;x>0;x-=x&-x)
    sm+=bit[id][x];
  return sm;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  long ans=0;
  for(int i=n;i>=1;i--)
  {
    ans+=get(2,aa[i]);
    upd(2,aa[i],get(1,aa[i]));
    upd(1,aa[i],1);
  }
  cout<<ans<<endl;
  return 0;
}