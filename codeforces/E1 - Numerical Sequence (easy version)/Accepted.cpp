/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/21/2019 18:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1216/problem/E1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long dig[16],lst[16];
long AP(long n,long first,long df)
{
  long ret=2*first+(n-1)*df;
  return (ret*n)/2;
}
void cal(void)
{
  long u=9;
  for(int i=1;i<=12;i++)
  {
    dig[i]=dig[i-1]+AP(u,lst[i-1]+i,i);
    lst[i]=lst[i-1]+u*i;
    u*=10;
  }
}
int digit(long x)
{
  int ret=0;
  while(x){x/=10;ret++;}
  return ret;
}
long abc(long x)
{
  if(!x)return 0;
  int dg=digit(x);dg--;
  long md=1;
  for(int i=1;i<=dg;i++)md*=10;
  return dig[dg]+AP(x-md+1,lst[dg]+dg+1,dg+1);
}
long def(long x)
{
  if(!x)return 0;
  int dg=digit(x);dg--;
  long md=1;
  for(int i=1;i<=dg;i++)md*=10;
  return lst[dg]+(x-md+1)*(dg+1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cal();
  int t;cin>>t;
  while(t--)
  {
    long k;cin>>k;
    long lo=0,hi=2e9,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(abc(md)>=k)hi=md;
      else lo=md;
    }
    for(md=lo;md<=hi;md++)
      if(abc(md)>=k)break;
    k-=abc(md-1);
    lo=0,hi=2e9,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(def(md)>=k)hi=md;
      else lo=md;
    }
    for(md=lo;md<=hi;md++)
      if(def(md)>=k)break;
    k-=def(md-1);
    vector<int>v;
    while(md){v.push_back(md%10);md/=10;}
    reverse(v.begin(),v.end());
    cout<<v[k-1]<<"\n";
  }
  return 0;
}