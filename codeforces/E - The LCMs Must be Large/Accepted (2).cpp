/****************************************************************************************
*  @author: kzvd4729                                         created: May/17/2019 23:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 10200 KB                             
*  problem: https://codeforces.com/contest/1166/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],vis[N+2];
vector<int>ls[52];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m,n;cin>>m>>n;
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;
    for(int j=1;j<=x;j++)
      cin>>aa[j],vis[aa[j]]=1;
    sort(aa+1,aa+x+1);
    for(int k=1;k<i;k++)
    {
      int pt=1;
      for(auto x:ls[k])
        if(x==aa[pt])pt++;
      if(pt>x)cout<<"impossible"<<endl,exit(0);
    }
    for(int j=1;j<=n;j++)
    {
      if(vis[j])vis[j]=0;
      else ls[i].push_back(j);
    }
  }
  cout<<"possible"<<endl;
  return 0;
}