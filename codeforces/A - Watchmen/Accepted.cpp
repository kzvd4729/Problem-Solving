/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/02/2019 10:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 607 ms                                          memory_used: 25100 KB                             
*  problem: https://codeforces.com/contest/650/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int xx[N+2],yy[N+2];
map<int,int>m1,m2;
map<pair<int,int>,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x,y;cin>>x>>y;xx[i]=x;yy[i]=y;
    m1[x]++;m2[y]++;
    mp[{x,y}]++;
  }
  long ans=0;
  for(int i=1;i<=n;i++)
  {
    int x=xx[i],y=yy[i];
    ans+=m1[x]-1;ans+=m2[y]-1;
    ans-=mp[{x,y}]-1;
  }
  cout<<ans/2<<endl;
  return 0;
}