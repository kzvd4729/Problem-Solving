/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-17 02:38:45                      
*  solution_verdict: Compile Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-3468
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
long bit[2][N+2],aa[N+2];
void upd(int x,long ml,long sm)
{
  for( ;x<=N;x+=(x&-x))
    bit[0][x]+=ml,bit[1][x]+=sm;
}
long get(int x)
{
  long ml=0,sm=0,bg=x;
  for( ;x>0;x-=(x&-x))
    ml+=bit[0][x],sm+=bit[1][x];
  return ml*bg+sm;
}
void range(int lo,int hi,long vl)
{
  upd(lo,vl,-vl*(lo-1));
  upd(hi,-vl,vl*hi);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];range(i,i,aa[i]);
  }
  while(q--)
  {
    char c;cin>>c;
    if(c=='C')
    {
      long lo,hi,vl;cin>>lo>>hi>>vl;
      range(lo,hi,vl);
    }
    else
    {
      long lo,hi;cin>>lo>>hi;
      cout<<get(hi)-get(lo-1)<<"\n";
    }
  }
  return 0;
}