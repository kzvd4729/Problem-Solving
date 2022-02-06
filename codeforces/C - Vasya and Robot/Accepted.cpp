/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/26/2018 00:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/1073/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int xx[N+2],yy[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;
  int dx,dy;cin>>dx>>dy;int x=0,y=0;
  for(int i=1;i<=n;i++)
  {
    if(s[i-1]=='U')y++;
    if(s[i-1]=='D')y--;
    if(s[i-1]=='L')x--;
    if(s[i-1]=='R')x++;
    xx[i]=x;yy[i]=y;
  }
  if(x==dx&&y==dy)cout<<0<<endl,exit(0);
  int ans=1e9;
  for(int i=1;i<=n;i++)
  {
    int lo=1,hi=i,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      int nx=x-(xx[i]-xx[md-1]);
      int ny=y-(yy[i]-yy[md-1]);
      if(i-md+1>=abs(dx-nx)+abs(dy-ny))lo=md;
      else hi=md;
    }
    //cout<<lo<<" "<<hi<<endl;
    for(md=min(i,hi+3);md>=max(1,lo-3);md--)
    {
      int nx=x-(xx[i]-xx[md-1]);
      int ny=y-(yy[i]-yy[md-1]);
      if(i-md+1==abs(dx-nx)+abs(dy-ny))ans=min(ans,i-md+1);
    }
  }
  if(ans==1000000000)ans=-1;
  cout<<ans<<endl;
  return 0;
}