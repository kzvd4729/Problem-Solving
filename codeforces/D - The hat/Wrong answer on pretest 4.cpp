/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/11/2018 21:34                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/1020/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inv=1e9+1;
const int N=2e5;
int n,d,ask[N+2];
pair<int,int>find_extreme(int lo,int hi)
{
  int a=min(ask[lo],ask[hi]);
  int b=max(ask[lo],ask[hi]);
   int dff=b-a;
  int inmd=hi-lo-1;
   if(dff>inmd)return {a,b};
  else return {a-((inmd-dff+1)/2),b+((inmd-dff+1)/2)};
}
void divide(int lo,int hi)
{
  if(lo>hi)return ;
  int llo=lo+(n/2),hhi=hi+(n/2);
  if(ask[lo]==inv)
  {
    cout<<"? "<<lo<<endl;
    fflush(stdout);
    cin>>ask[lo];
  }
  if(ask[llo]==inv)
  {
    cout<<"? "<<llo<<endl;
    fflush(stdout);
    cin>>ask[llo];
  }
  if(ask[lo]==ask[llo])
    cout<<"! "<<lo<<endl,exit(0);
  if(ask[hi]==inv)
  {
    cout<<"? "<<hi<<endl;
    fflush(stdout);
    cin>>ask[hi];
  }
  if(ask[hhi]==inv)
  {
    cout<<"? "<<hhi<<endl;
    fflush(stdout);
    cin>>ask[hhi];
  }
  if(ask[hi]==ask[hhi])
    cout<<"! "<<hi<<endl,exit(0);
   int md1=(lo+hi)/2;
  int md2=(md1+n/2);
  if(ask[md1]==inv)
  {
    cout<<"? "<<md1<<endl;
    fflush(stdout);
    cin>>ask[md1];
  }
  if(ask[md2]==inv)
  {
    cout<<"? "<<md2<<endl;
    fflush(stdout);
    cin>>ask[md2];
  }
  if(ask[md1]==ask[md2])
    cout<<"! "<<md1<<endl,exit(0);
   pair<int,int>p;
   p=find_extreme(lo,md1);
  int mn1=p.first;
  int mx1=p.second;
   p=find_extreme(llo,md2);
  int mn2=p.first;
  int mx2=p.second;
   if((mn1>=mn2&&mn1<=mx2)||(mx1>=mn2&&mx1<=mx2)||(mn1<=mn2&&mx1>=mx2))
  {
    if(lo!=hi)divide(lo,md1-1);
  }
  else
  {
    if(lo!=hi)divide(md1+1,hi);
  }
 }
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;d=n/2;
  if(d%2)cout<<"! -1"<<endl,exit(0);
  for(int i=1;i<=n;i++)
    ask[i]=inv;
  divide(1,d);
   cout<<"! -1"<<endl,exit(0);
   return 0;
}