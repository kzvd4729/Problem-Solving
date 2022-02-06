/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/26/2019 21:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1157/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long inf=1e18;
/**************** Progressions *******************/
long AP(long n,long first,long df)
{
  if(n>1e5)return inf;
  long ret=2*first+(n-1)*df;
  return (ret*n)/2;
}
long GP(long n,long first,long fc)
{
  if(n>=30)return inf;
  long ret=first*(pow(fc,n)-1);
  return ret/(fc-1);
}
/////////////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;long st=-1;
   long lo=1,hi=n,md;
  while(lo<hi)
  {
    md=(lo+hi)/2;
    long lt=AP(k,md,1);
    long rt=GP(k,md,2);
    if(lt>n)hi=md;
    else if(rt<n)lo=md+1;
    else
    {
      st=md;break;
    }
  }
  if(st==-1)
  {
    long lt=AP(k,lo,1);
    long rt=GP(k,lo,2);
    if(n>=lt&&n<=rt)
      st=lo;
  }
  if(st==-1)cout<<"NO"<<endl,exit(0);
  cout<<"YES"<<endl;
  cout<<st<<" ";n-=st;
  for(int i=2;i<=k;i++)
  {
    long lo=st+1,hi=2*st,md,f=0;
    while(lo<hi)
    {
      md=(lo+hi)/2;
      long lt=AP(k-i+1,md,1);
      long rt=GP(k-i+1,md,2);
      if(lt>n)hi=md;
      else if(rt<n)lo=md+1;
      else
      {
        cout<<md<<" ";n-=md;f=1;
        st=md;break;
      }
    }
    if(f==0)
    {
      cout<<lo<<" ";n-=lo;
      st=lo;
    }
  }
  cout<<endl;
  return 0;
}