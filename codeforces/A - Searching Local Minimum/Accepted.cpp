/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/07/2021 21:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1479/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
  vector<int>v;int n;
int ask(int x)
{
  if(x==0||x==n+1)return inf;
  cout<<"? "<<x<<endl;
  int vl;cin>>vl;
   return vl;
}
void print(int x)
{
  cout<<"! "<<x<<endl;
  exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
  int lo=1,hi=n,md,f=0;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    int a=ask(md-1),b=ask(md),c=ask(md+1);
     if(a>b&&c>b)print(md);
    if(a>b)lo=md;else hi=md;
    //cout<<lo<<" "<<hi<<endl;
  }
  for(md=lo;md<=hi;md++)
  {
    int a=ask(md-1),b=ask(md),c=ask(md+1);
    //cout<<md<<" "<<a<<" "<<b<<" "<<c<<endl;
    if(a>b&&c>b)print(md);
  }
  assert(0);
   return 0;
}