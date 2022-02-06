/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/27/2020 20:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 170 ms                                          memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/634/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6,inf=1e9;
int bit[N+2],bit1[N+2];
void upd(int x,int vl){for( ;x<=N;x+=x&-x)bit[x]+=vl;}
int get(int x)
{
  int ret=0;for( ;x>0;x-=x&-x)ret+=bit[x];
  return ret;
}
void upd1(int x,int vl){for( ;x>0;x-=x&-x)bit1[x]+=vl;}
int get1(int x)
{
  int ret=0;
  for( ;x<=N;x+=x&-x)ret+=bit1[x];
  return ret;
}
int cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k,a,b,q;cin>>n>>k>>a>>b>>q;
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int d,v;cin>>d>>v;
      upd(d,-min(cnt[d],b));upd1(d,-min(cnt[d],a));
      cnt[d]+=v;
      upd(d,min(cnt[d],b));upd1(d,min(cnt[d],a));
    }
    else
    {
      int d;cin>>d;
      cout<<get(d-1)+get1(d+k)<<"\n";
    }
  }
  return 0;
}