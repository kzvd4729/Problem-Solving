/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/23/2019 19:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1155/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
const long mod=1e6+3;
long bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
long inv(long x)
{
  return bigmod(x,mod-2,mod);
}
void gauss(vector<vector<long>>a,vector<long>&ans)
{
  long n=a.size(),m=a[0].size()-1;
  vector<long>wh(m,-1);
  for(long col=0,row=0;col<m&&row<n;col++)
  {
    long swp=-1;
    for(long i=row;i<n;i++)
    {
      if(a[i][col])
      {
        swp=i;break;
      }
    }
    if(swp==-1)continue;
    for(long i=col;i<=m;i++)swap(a[row][i],a[swp][i]);
    wh[col]=row;
    for(long i=0;i<n;i++)
    {
      if(i==row)continue;
      long c=(a[i][col]*inv(a[row][col]))%mod;
      for(long j=0;j<=m;j++)
        a[i][j]=(a[i][j]-(a[row][j]*c)%mod+mod)%mod;
    }
    row++;
  }
  ans.assign(m,0);
  for(long i=0;i<m;i++)
  {
    if(wh[i]==-1)continue;
    ans[i]=(a[wh[i]][m]*inv(a[wh[i]][i]))%mod;
  }
}
long eval(long x,vector<long>ans)
{
  long p=1,sum=0;
  for(long i=0;i<=10;i++)
  {
    sum=(sum+p*ans[i])%mod;
    p=(p*x)%mod;
  }
  return sum;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  vector<vector<long> >a;vector<long>ans,v;
  for(long i=0;i<=10;i++)
  {
    v.clear();long p=1;
    for(long j=0;j<=10;j++)
    {
      v.push_back(p);p=(p*i)%mod;
    }
    cout<<"? "<<i<<endl;long x;
    cin>>x;v.push_back(x);
    a.push_back(v);
  }
  gauss(a,ans);
  for(long i=0;i<mod;i++)
  {
    if(!eval(i,ans))cout<<"! "<<i<<endl,exit(0);
  }
  cout<<"! "<<-1<<endl;
  return 0;
}