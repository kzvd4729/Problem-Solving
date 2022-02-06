/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/24/2018 14:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1080/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
pair<long,long>ret(long a,long b,long c,long d)
{
   if(a>c||b>d)return {0,0};
   long i=(c-a+2)/2;long j=(d-b+2)/2;
  long k=(c-a+1)/2;long l=(d-b+1)/2;
   long wh=i*j+k*l;
  long bl=(c-a+1)*(d-b+1)-wh;
  if((a+b)%2)return {bl,wh};
  else return {wh,bl};
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int q;cin>>q;
  while(q--)
  {
    long n,m;cin>>n>>m;
    int a,b,c,d;cin>>a>>b>>c>>d;
    int e,f,g,h;cin>>e>>f>>g>>h;
     pair<long,long>p=ret(1,1,m,n);
     long wh=p.first,bl=p.second;
     long i=max(a,e);
    long j=max(b,f);
     long k=min(c,g);
    long l=min(d,h);
     p=ret(a,b,c,d);
     bl-=p.second;wh+=p.second;
     p=ret(i,j,k,l);
     bl+=p.second;wh-=p.second;
     p=ret(e,f,g,h);
     wh-=p.first;bl+=p.first;
     cout<<wh<<" "<<bl<<endl;
    }
  return 0;
}