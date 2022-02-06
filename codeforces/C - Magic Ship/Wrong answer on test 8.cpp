/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/18/2019 22:16                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1117/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long inf=1e18;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b,c,d;cin>>a>>b>>c>>d;
  int n;cin>>n;string s;cin>>s;
   int x=a,y=b;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='U')y++;
    else if(s[i]=='D')y--;
    else if(s[i]=='R')x++;
    else if(s[i]=='L')x--;
    if(abs(c-x)+abs(d-y)<=i+1)
      cout<<i+1<<endl,exit(0);
  }
  long ans=inf;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='U')b++;
    else if(s[i]=='D')b--;
    else if(s[i]=='R')a++;
    else if(s[i]=='L')a--;
     long lo=0,hi=1e9+1,md,day;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      day=md*n+i+1;
      long px=x*md+a,py=y*md+b;
      if(abs(px-c)+abs(py-d)<=day)hi=md;
      else lo=md;
    }
    for(md=lo;md<=hi;md++)
    {
      day=md*n+i+1;
      long px=x*md+a,py=y*md+b;
      if(abs(px-c)+abs(py-d)<=day)
      {
        ans=min(ans,day);
        break;
      }
    }
  }
  if(ans==inf)cout<<-1<<endl;
  else cout<<ans<<endl;
  return 0;
}