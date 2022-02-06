/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/05/2018 23:26                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 327 ms                                          memory_used: 1700 KB                              
*  problem: https://codeforces.com/contest/724/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,m,k,ans[N+2];
pair<int,int>pp[N+2];
map<pair<int,int>,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>k;
  for(int i=1;i<=k;i++)
  {
    int x,y;cin>>x>>y;
    mp[{x,y}]=i;
  }
  int loop=6e6;int x=0,y=0,a=1,b=1;
  for(int i=1;i<=loop;i++)
  {
    x+=a;y+=b;
    if(x>n)x=n-1,a=-1;
    if(y>m)y=m-1,b=-1;
    if(x<0)x=1,a=1;
    if(y<0)y=1,b=1;
    if(mp.find({x,y})!=mp.end())
    {
      if(ans[mp[{x,y}]]==0)ans[mp[{x,y}]]=i;
    }
  }
  for(int i=1;i<=k;i++)
  {
    if(!ans[i])ans[i]=-1;
    cout<<ans[i]<<" ";
  }
  return 0;
}