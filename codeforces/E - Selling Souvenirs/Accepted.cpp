/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/19/2020 17:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 52000 KB                             
*  problem: https://codeforces.com/contest/808/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>v[N+2];long sm[3+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int ty,w;cin>>ty>>w;
    v[ty].push_back(w);
  }
  for(int i=1;i<=3;i++)
    sort(v[i].begin(),v[i].end(),greater<int>());
   for(int i=1;i<=3;i++)if(v[i].size())sm[i][1]=v[i][0];
   for(int i=1;i<=3;i++)
  { 
    for(int j=2;j<=v[i].size();j++)
      sm[i][j]=sm[i][j-1]+v[i][j-1];
     for(int j=1;j<=m;j++)
      sm[i][j]=max(sm[i][j],sm[i][j-1]);
  }
  long ans=0;
  for(int i=0;i<=m/3;i++)
  {
    long now=sm[3][i];int rm=m-i*3;
    int lo=0,hi=rm/2,md1,md2;
    while(hi-lo>2)
    {
      md1=(lo+lo+hi)/3,md2=(lo+hi+hi)/3;
      if(sm[2][md1]+sm[1][rm-md1*2]>sm[2][md2]+sm[1][rm-md2*2])hi=md2;
      else lo=md1;
    }
    long mx=0;
    for(int md=lo;md<=hi;md++)
      mx=max(mx,sm[2][md]+sm[1][rm-md*2]);
    ans=max(ans,now+mx);
  }
  cout<<ans<<endl;
  return 0;
}