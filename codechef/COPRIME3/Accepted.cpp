/****************************************************************************************
*  @author: kzvd4729                                         created: 25-01-2020 19:19:19                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.29 sec                                        memory_used: 55.8M                                
*  problem: https://www.codechef.com/problems/COPRIME3
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int mb[N+2],vis[N+2];
void mobius()
{
  for(int i=1;i<=N;i++)mb[i]=1;
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      mb[j]*=-1;vis[j]=1;
      if(i<=30000&&(j%(i*i)==0))mb[j]=0;
    }
  }
}
vector<int>d[N+2];
vector<int>divisors(int x)
{
  if(d[x].size()>0)return d[x];
  int sq=sqrt(x+1);vector<int>ret;
  for(int i=1;i<=sq;i++)
  {
    if(x%i)continue;ret.push_back(i);
    if(i!=x/i)ret.push_back(x/i);
  }
  sort(ret.begin(),ret.end());
  return d[x]=ret;
}
int cnt[N+2];
long ncr(int n)
{
  long ret=1LL*n*(n-1)*(n-2);
  return ret/6;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  mobius();int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int z;cin>>z;divisors(z);
    for(auto x:d[z])cnt[x]++;
  }
  long ans=0;
  for(int i=1;i<=N;i++)
    ans+=mb[i]*ncr(cnt[i]);
  cout<<ans<<endl;
  return 0;
}