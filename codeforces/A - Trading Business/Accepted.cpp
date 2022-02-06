/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2019 19:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 4300 KB                              
*  problem: https://codeforces.com/contest/176/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[102][102][102];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
   for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int ii=1;ii<=m;ii++)
    {
      for(int jj=1;jj<=3;jj++)
      {
        cin>>aa[i][ii][jj];
      }
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(i==j)continue;
      priority_queue<pair<int,int> >pq;
      for(int ii=1;ii<=m;ii++)
      {
        pq.push({aa[j][ii][2]-aa[i][ii][1],aa[i][ii][3]});
      }
      int now=0,kk=k;
      while(pq.size())
      {
        pair<int,int>p=pq.top();pq.pop();
        if(p.first<=0)break;
        int mn=min(kk,p.second);
        now+=mn*p.first;kk-=mn;
      }
      ans=max(ans,now);
    }
  }
  cout<<ans<<endl;
  return 0;
}