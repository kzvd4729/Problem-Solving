/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2020 20:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 170 ms                                          memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/379/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
pair<int,int>pp[N+2];int ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>pp[i].first;pp[i].second=i;
  }
  sort(pp+1,pp+n+1);
  int now=0;
  for(int i=1;i<=n;i++)
  {
    if(pp[i].first<=now)pp[i].first=++now;
    else now=pp[i].first;
    ans[pp[i].second]=pp[i].first;
  }
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
  return 0;
}