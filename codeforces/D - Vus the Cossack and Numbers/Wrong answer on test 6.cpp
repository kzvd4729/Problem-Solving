/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/29/2019 14:46                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 19700 KB                             
*  problem: https://codeforces.com/contest/1186/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
double aa[N+2];
int ng[N+2],ps[N+2],pr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  int nmn=0,nmx=0,pmn=0,pmx=0;
  for(int i=1;i<=n;i++)
  {
    double x;cin>>x;aa[i]=x;
    if(x<0.0)
    {
      nmx-=(int)floor(x),nmn-=(int)ceil(x);
      ng[i]=nmx;
    }
    else
    {
      pmn+=(int)floor(x),pmx+=(int)ceil(x);
      ps[i]=pmx;
    }
  }
  int tr;
  if(nmn>=pmn&&nmn<=pmx)tr=nmn;
  else if(nmx>=pmn&&nmx<=pmx)tr=nmx;
  else if(pmn>=nmn&&pmn<=nmx)tr=pmn;
  else if(pmx>=nmn&&pmx<=nmx)tr=pmx;
  int cn=0,cp=0;
  for(int i=n;i>=1;i--)
  {
    double x=aa[i];
    if(x<0.0)
    {
      int s=-(int)ceil(x);
      int b=-(int)floor(x);
      if(ng[i]+cn>tr)pr[i]=-s,cn+=s;
      else pr[i]=b,cn+=b;
    }
    else
    {
      int s=(int)floor(x);
      int b=(int)ceil(x);
      if(ps[i]+cp>tr)pr[i]=s,cp+=s;
      else pr[i]=b,cp+=b;
    }
  }
  for(int i=1;i<=n;i++)
    cout<<pr[i]<<" ";
  cout<<endl;
  return 0;
}