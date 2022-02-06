/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/04/2018 00:55                        
*  solution_verdict: Time limit exceeded on test 6           language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 16100 KB                             
*  problem: https://codeforces.com/contest/959/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const int NN=2e6;
int vis[N+2],vss[NN+2],f,b[N+2],arr[N+2],n,id;
vector<int>fac[N+2];
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
void kato(int x)
{
  for(int j=x;j<=NN;j+=x)vss[j]=1;
}
int main()
{
  prime_factorize();
   scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
  for(int i=1;i<=n;i++)
  {
    if(vss[arr[i]])
    {
      id=i;
      for(int ii=2;ii<=NN;ii++)
      {
        if(id>n)exit(0);
        if(vss[ii]==0)
        {
          printf("%d ",ii);
          for(auto z:fac[ii])if(vss[z]==0)kato(z);
          id++;
        }
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