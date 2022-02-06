/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/29/2019 14:48                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 31500 KB                             
*  problem: https://codeforces.com/contest/1186/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
double aa[N+2];
long ng[N+2],ps[N+2],pr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  long nmn=0,nmx=0,pmn=0,pmx=0;
  for(long i=1;i<=n;i++)
  {
    double x;cin>>x;aa[i]=x;
    if(x<0.0)
    {
      nmx-=(long)floor(x),nmn-=(long)ceil(x);
      ng[i]=nmx;
    }
    else
    {
      pmn+=(long)floor(x),pmx+=(long)ceil(x);
      ps[i]=pmx;
    }
  }
  long tr;
  if(nmn>=pmn&&nmn<=pmx)tr=nmn;
  else if(nmx>=pmn&&nmx<=pmx)tr=nmx;
  else if(pmn>=nmn&&pmn<=nmx)tr=pmn;
  else if(pmx>=nmn&&pmx<=nmx)tr=pmx;
  else assert(0);
  long cn=0,cp=0;
  for(long i=n;i>=1;i--)
  {
    double x=aa[i];
    if(x<0.0)
    {
      long s=-(long)ceil(x);
      long b=-(long)floor(x);
      if(ng[i]+cn>tr)pr[i]=-s,cn+=s;
      else pr[i]=b,cn+=b;
    }
    else
    {
      long s=(long)floor(x);
      long b=(long)ceil(x);
      if(ps[i]+cp>tr)pr[i]=s,cp+=s;
      else pr[i]=b,cp+=b;
    }
  }
  for(long i=1;i<=n;i++)
    cout<<pr[i]<<" ";
  cout<<endl;
  return 0;
}