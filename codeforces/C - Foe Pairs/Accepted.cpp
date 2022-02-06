/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/08/2019 12:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 234 ms                                          memory_used: 19600 KB                             
*  problem: https://codeforces.com/contest/652/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int po[N+2],aa[N+2],mn[N+2];
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];po[aa[i]]=i;
  }
  for(int i=1;i<=m;i++)
  {
    cin>>pp[i].first>>pp[i].second;
    if(po[pp[i].first]>po[pp[i].second])
      swap(pp[i].first,pp[i].second);
    pp[i].first=po[pp[i].first];
    pp[i].second=po[pp[i].second];
  }
  sort(pp+1,pp+m+1);pp[m+1]={1e9,1e9};mn[m+1]=n+1;
  for(int i=m;i>=1;i--)
    mn[i]=min(mn[i+1],pp[i].second);
  int pt=1;long ans=0;
  for(int i=1;i<=n;i++)
  {
    while(pp[pt].first<i)pt++;
    ans+=(mn[pt]-i)*1LL;
  }
  cout<<ans<<endl;
  return 0;
}