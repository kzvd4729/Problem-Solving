/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/28/2018 21:34                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1082/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int qm[N+2];
pair<int,int>ord[N+2];
vector<int>vc[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int u,v;cin>>u>>v;
    vc[u].push_back(v);
  }
  for(int i=1;i<=m;i++)
    sort(vc[i].begin(),vc[i].end(),greater<int>());
    for(int i=1;i<=m;i++)
    ord[i]={vc[i].size(),i};
   sort(ord+1,ord+m+1,greater<pair<int,int> >());
   // for(int i=1;i<=m;i++)
  //   cout<<ord[i].second<<" ";
  // cout<<endl;
   int ans=0;
  for(int i=1;i<=n;i++)
  {
    int here=0;
    for(int jj=1;jj<=m;jj++)
    {
      int j=ord[jj].second;
      if(vc[j].size()<i)break;
      qm[j]+=vc[j][i-1];
      here+=qm[j];
    }
    ans=max(ans,here);
  }
  cout<<ans<<endl;
  return 0;
}