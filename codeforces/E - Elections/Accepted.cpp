/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/01/2019 13:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1267/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2,inf=1e9;
int mt[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
      cin>>mt[i][j];
  }
  vector<int>ans(1e4);
  for(int i=1;i<n;i++)
  {
    int sm=0;vector<pair<int,int> >v;
    for(int j=1;j<=m;j++)
    {
      sm+=mt[j][n]-mt[j][i];
      v.push_back({mt[j][n]-mt[j][i],j});
    }
    sort(v.begin(),v.end());
    vector<int>now;
    while(true)
    {
      if(sm<=0)
      {
        if(now.size()<ans.size())ans=now;
        break;
      }
      if(v.size()==0)break;
      sm-=v.back().first;now.push_back(v.back().second);
      v.pop_back();
    }
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)cout<<x<<" ";
    cout<<endl;
  return 0;
}