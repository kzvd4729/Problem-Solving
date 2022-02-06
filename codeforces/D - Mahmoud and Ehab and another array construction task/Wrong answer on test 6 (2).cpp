/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/04/2018 01:10                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 25500 KB                             
*  problem: https://codeforces.com/contest/959/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const int NN=2e6;
int vis[N+2],vss[NN+2],f,b[N+2],arr[N+2],n,id,vs[NN+2];
vector<int>fac[N+2],pr;
void prime_factorize()
{
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      vis[j]=1;
      fac[j].push_back(i);
    }
  }
}
void seive(void)
{
  int lim=sqrt(NN+1);
  memset(vs,0,sizeof(vs));
  for(int i=4;i<=NN;i+=2)vs[i]=1;
  pr.push_back(2);
  for(int i=3;i<=NN;i+=2)
  {
    if(vs[i])continue;
    pr.push_back(i);
    if(i>lim)continue;
    for(int j=i*i;j<=NN;j+=2*i)vs[j]=1;
  }
  //for(int i=0;i<10;i++)cout<<pr[i]<<" ";
}
void kato(int x)
{
  for(int j=x;j<=NN;j+=x)vss[j]=1;
}
int main()
{
  prime_factorize();
  seive();
   scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
  for(int i=1;i<=n;i++)
  {
    if(vss[arr[i]])
    {
      id=i;
      for(auto xx:pr)
      {
        if(id>n)return 0;
        if(vss[xx])continue;
        printf("%d ",xx);
        id++;
      }
    }
    else
    {
      printf("%d ",arr[i]);
      for(auto z:fac[arr[i]])if(vss[z]==0)kato(z);
    }
  }
  return 0;
}