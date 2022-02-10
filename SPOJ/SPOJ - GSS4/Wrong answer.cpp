/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-14 21:14:52                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-GSS4
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
long aa[N+2],bit[N+2],n,par[N+2];
void upd(long x,long vl)
{
  for( ;x<=n;x+=x&-x)bit[x]+=vl;
}
long get(long x)
{
  long sum=0;
  for( ;x>0;x-=x&-x)sum+=bit[x];
  return sum;
}
long find(long x)
{
  if(x==par[x])return x;
  return par[x]=find(par[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long tc=0;
  while(cin>>n)
  {
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=n;i++)bit[i]=0;

    for(int i=1;i<=n;i++)par[i]=i,upd(i,aa[i]);
    long q;cin>>q;cout<<"Case #"<<++tc<<":"<<endl;
    while(q--)
    {
      long ty,lt,rt;cin>>ty>>lt>>rt;
      if(ty==1)cout<<get(rt)-get(lt-1)<<endl;
      else
      {
        while(lt<=rt)
        {
          long x=find(lt);if(x>rt)break;
          long sq=sqrt(aa[x]);
          upd(x,sq-aa[x]);aa[x]=sq;
          if(sq==1)par[x]=x+1;
          lt=x+1;
        }
      }
    }
    cout<<endl;
  }
  return 0;
}