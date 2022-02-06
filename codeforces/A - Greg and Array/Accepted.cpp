/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/16/2019 18:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 47000 KB                             
*  problem: https://codeforces.com/contest/295/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long aa[N+2],qm[N+2],sm[N+2],l[N+2],r[N+2],d[N+2];
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n,m,k;cin>>n>>m>>k;
 for(int i=1;i<=n;i++)cin>>aa[i];
 for(int i=1;i<=m;i++)
  cin>>l[i]>>r[i]>>d[i];
 for(int i=1;i<=k;i++)
 {
  int x,y;cin>>x>>y;
  qm[x]++;qm[y+1]--;
 }
 for(int i=1;i<=m;i++)
 {
  qm[i]+=qm[i-1];
  sm[l[i]]+=d[i]*qm[i];
  sm[r[i]+1]-=d[i]*qm[i];
 }
 for(int i=1;i<=n;i++)
 {
  sm[i]+=sm[i-1];
  cout<<aa[i]+sm[i]<<" ";
 }
 cout<<endl;
 return 0;
}