/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-10 11:22:11                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 6                                          memory_used (MB): 2.1                             
*  problem: https://vjudge.net/problem/LightOJ-1272
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=64;
/*********** Gaussian Elemination ************/
bitset<N>Gauss(vector<bitset<N> >a) 
{
  int n=a.size(),m=N;vector<int>wh(m,-1);
  for(int col=0,row=0;col<m&&row<n;col++) 
  {
    for(int i=row;i<n;i++)
    {
      if(a[i][col]) 
      {
        swap(a[i],a[row]);break;
      }
    }
    if(!a[row][col])
      continue;
    wh[col]=row;
    for(int i=0;i<n;i++)
      if(i!=row&&a[i][col])
        a[i]^=a[row];
    ++row;
  }
  bitset<N>ret;
  for(int j=0;j<m;j++)
    for(int i=0;i<n;i++)
      ret[j]=ret[j]^a[i][j];
  return ret;
}
int main()
{
  int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    int n;scanf("%d",&n);vector<bitset<N> >a;
    for(int ii=1;ii<=n;ii++)
    {
      long x;scanf("%lld",&x);bitset<N>bt;
      for(long i=63;i>=0;i--)
        if(x&(1LL<<i))bt[63-i]=1;
      a.push_back(bt);
    }
    bitset<N>bt=Gauss(a);long ans=0;
    for(long i=0;i<N;i++)
      if(bt[i])ans|=(1LL<<(63-i));
    printf("Case %d: %lld\n",++tc,ans);
  }
  return 0;
}