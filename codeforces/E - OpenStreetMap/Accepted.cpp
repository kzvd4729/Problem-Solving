/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/18/2019 10:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 655 ms                                          memory_used: 211500 KB                            
*  problem: https://codeforces.com/contest/1195/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=3e3;
long gg[N*N+2],mt[N+2][N+2],tmp[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m,a,b;cin>>n>>m>>a>>b;
  long x,y,z;cin>>gg[0]>>x>>y>>z;
  for(long i=1;i<=n*m;i++)
    gg[i]=(gg[i-1]*x+y)%z;
  for(long i=1;i<=n;i++)
    for(long j=1;j<=m;j++)
      mt[i][j]=gg[(i-1)*m+j-1];
  for(long i=1;i<=n;i++)
  {
    deque<pair<long,long> >dq;
    for(long j=1;j<=m;j++)
    {
      while(dq.size())
      {
        if(dq.back().first>=mt[i][j])
          dq.pop_back();
        else break;
      }
      dq.push_back({mt[i][j],j});
      if(dq.front().second<=j-b)dq.pop_front();
      if(j-b+1>0)
      {
        tmp[i][j-b+1]=dq.front().first;
        //cout<<dq.front().first<<" ";
      }
    }
    //cout<<endl;
  }
  long ans=0;
  for(long j=1;j<=m-b+1;j++)
  {
    deque<pair<long,long> >dq;
    for(long i=1;i<=n;i++)
    {
      while(dq.size())
      {
        if(dq.back().first>=tmp[i][j])
          dq.pop_back();
        else break;
      }
      dq.push_back({tmp[i][j],i});
      if(dq.front().second<=i-a)dq.pop_front();
      if(i-a+1>0)ans+=dq.front().first;
    }
  }
  cout<<ans<<endl;
  return 0;
}