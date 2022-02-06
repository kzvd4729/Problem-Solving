/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/10/2020 22:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3700 KB                              
*  problem: https://codeforces.com/contest/1166/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long a,b,m;cin>>a>>b>>m;
    if(a>b){cout<<-1<<endl;continue;}
    if(a==b){cout<<1<<" "<<a<<endl;continue;};
    int ln=1,f=0;long mn=a,mx=a;
    while(true)
    {
      ln++;
      //cout<<mn+1<<" "<<mx+m<<endl;
      if(b>=mn+1&&b<=mx+m)break;
      if(mn+1>b){f=1;break;}
      mn=mn+mn+1,mx=mx+mx+m;
    }
    if(f){cout<<-1<<endl;continue;};
    cout<<ln<<" "<<a;
    mn=a,mx=a;
    for(int i=3;i<=ln;i++)
    {
      long lo=mn+1,hi=mx+m,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;long tmn=mn+md,tmx=mx+md;
        for(int j=i+1;j<=ln;j++)tmn=tmn+tmn+1,tmx=tmx+tmx+m;
        tmn++,tmx+=m;
        if(tmn>b)hi=md;else lo=md;
      }
      for(md=lo;md<=hi;md++)
      {
        long tmn=mn+md,tmx=mx+md;
        for(int j=i+1;j<=ln;j++)tmn=tmn+tmn+1,tmx=tmx+tmx+m;
        tmn++,tmx+=m;
        if(b>=tmn&&b<=tmx)break;
      }
      cout<<" "<<md;
      mn=mn+md,mx=mx+md;
      //cout<<mn<<" "<<mx<<endl;
    }
    cout<<" "<<b<<endl;
  }
  return 0;
}