/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/17/2019 19:50                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 295 ms                                          memory_used: 103300 KB                            
*  problem: https://codeforces.com/contest/1175/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=3e5;
long n,aa[N+2];long qm[N+2],sp[N+2][42];
void build(void)
{
  for(long i=1;i<=n;i++)
    sp[i][0]=qm[i],sp[i][20]=i;
  for(long j=1;j<20;j++)
  {
    for(long i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];sp[i][j+20]=sp[i][j-1+20];
      if((i+(1<<(j-1)))>n)continue;
      if(sp[i+(1<<(j-1))][j-1]<sp[i][j])
        sp[i][j]=sp[i+(1<<(j-1))][j-1],sp[i][j+20]=sp[i+(1<<(j-1))][j-1+20];
    }
  }
}
pair<long,long>get(long lt,long rt)
{
  long dg=31-__builtin_clz(rt-lt+1);
  if(sp[lt][dg]<sp[rt-(1<<dg)+1][dg])
    return {sp[lt][dg],sp[lt][dg+20]};
  else return {sp[rt-(1<<dg)+1][dg],sp[rt-(1<<dg)+1][dg+20]};
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long k;cin>>n>>k;
  for(long i=1;i<=n;i++)
    cin>>aa[i],qm[i]=qm[i-1]+aa[i];
  build();long id=1;long sm=0,tt=0;
  for(long i=1;i<k;i++)
  {
    sm+=aa[id];long id2;
    long lt=id+1,rt=n-(k-i);
    if(lt>rt)id2=id;
    else
    {
      pair<long,long>p=get(lt,rt);
      p.first-=sm;
      if(p.first<0)id2=p.second;
      else id2=id;
    }
    tt+=(qm[id2]-qm[id-1])*i;
    sm+=qm[id2]-qm[id];id=id2+1;
  }
  tt+=(qm[n]-qm[id-1])*k;
  cout<<tt<<endl;
  return 0;
}