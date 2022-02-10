/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-05 12:00:12                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 32                                         memory_used (MB): 13.7                            
*  problem: https://vjudge.net/problem/POJ-2478
****************************************************************************************/
#include<iostream>
#define long long long
using namespace std;
const int N=1e6;
long qm[N+2];
bool isComposit[N+2];
int prime[N/10+2],p,phi[N+2];
void linearSieve(int n)
{
  isComposit[0]=isComposit[1]=1;
  for(int i=2;i<=n;i++)
  {
    if(!isComposit[i])prime[++p]=i,phi[i]=i-1;
    for(int j=1;j<=p&&i*prime[j]<=n;j++)
    {
      isComposit[i*prime[j]]=1;
      if(i%prime[j]==0)
      {
        phi[i*prime[j]]=phi[i]*prime[j];
        break;
      }
      else phi[i*prime[j]]=phi[i]*phi[prime[j]];
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  linearSieve(N);
  for(int i=1;i<=N;i++)qm[i]=qm[i-1]+phi[i];

  int n;
  while(cin>>n)
  {
    if(!n)break;
    cout<<qm[n]<<"\n";
  }
  return 0;
}