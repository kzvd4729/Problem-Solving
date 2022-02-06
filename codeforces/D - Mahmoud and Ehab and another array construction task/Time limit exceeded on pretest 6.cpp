/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2018 23:53                        
*  solution_verdict: Time limit exceeded on pretest 6        language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 20400 KB                             
*  problem: https://codeforces.com/contest/959/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int NN=3e6;
int vis[N+2],kat[N+2],vss[NN+2],f,b[N+2],arr[N+2],n,id;
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
  for(int i=x;i<=NN;i+=x)vss[i]=1;
}
void print(void)
{
  for(int i=1;i<=n;i++)cout<<b[i]<<" ";
  cout<<endl;
  exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   prime_factorize();
   cin>>n;
  for(int i=1;i<=n;i++)cin>>arr[i];
  for(int i=1;i<=n;i++)
  {
    if(vss[arr[i]])
    {
      id=i;
      for(int ii=2;ii<=NN;ii++)
      {
        if(id>n)print();
        if(vss[ii]==0)
        {
          b[id]=ii;
          for(auto z:fac[ii])if(vss[z]==0)kato(z);
          id++;
        }
      }
    }
    else
    {
      b[i]=arr[i];
      for(auto z:fac[arr[i]])if(vss[z]==0)kato(z);
    }
  }
  print();
  return 0;
}