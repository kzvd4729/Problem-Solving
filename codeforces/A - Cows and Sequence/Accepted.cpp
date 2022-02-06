/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/01/2019 09:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1029 ms                                         memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/283/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
long bit[N+2];
void upd(int x,long vl)
{
  for( ;x<=N;x+=x&-x)
    bit[x]+=vl;
}
long qry(long x)
{
  long sm=0;
  for( ;x>0;x-=x&-x)
    sm+=bit[x];
  return sm;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long sz=1,sum=0;
  while(n--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      long a,x;cin>>a>>x;sum+=a*x;
      upd(1,x);upd(a+1,-x);
    }
    else if(ty==2)
    {
      long x;cin>>x;sum+=x;
      upd(++sz,x);upd(sz+1,-x);
    }
    else
    {
      long x=qry(sz);sum-=x;
      upd(sz,-x);upd(sz+1,x);
      sz--;
    }
    double ans=(sum*1.0)/(sz*1.0);
    cout<<setprecision(6)<<fixed<<ans<<endl;
  }
  return 0;
}