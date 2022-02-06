/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/05/2018 13:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 561 ms                                          memory_used: 43800 KB                             
*  problem: https://codeforces.com/contest/846/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>pos[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=N;i++)pos[i].push_back(0);
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;pos[x].push_back(i);
  }
  long ans=0;
  for(int i=1;i<=N;i++)
  {
    pos[i].push_back(n+1);
    long now=n*1LL*n;
    for(int j=1;j<pos[i].size();j++)
    {
      long df=pos[i][j]-pos[i][j-1]-1;
      now-=df*df;
    }
    ans+=now;
  }
  long dn=n*1LL*n;
   double pr=(ans*1.0)/(dn*1.0);
   cout<<setprecision(10)<<fixed<<pr<<endl;
   return 0;
}