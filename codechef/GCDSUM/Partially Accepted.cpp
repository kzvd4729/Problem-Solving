/****************************************************************************************
*  @author: kzvd4729                                         created: 28-07-2018 22:09:56                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.12 sec                                        memory_used: 31.9M                                
*  problem: https://www.codechef.com/LTIME62A/problems/GCDSUM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const int N=1e5;
int n,m,arr[22][N+2];
long tmp[N+2],fr[N+2];
vector<int>dv[N+2];
void seive(void)
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)
    {
      dv[j].push_back(i);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  seive();
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>arr[i][j];
    }
  }
  for(int j=1;j<=m;j++)
  {
    for(auto xx:dv[arr[1][j]])
      fr[xx]++;
  }
  long ans=0;
  for(int i=2;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      int x=arr[i][j];
      for(int k=dv[x].size()-1;k>=0;k--)
      {
        int xx=dv[x][k];
        ans=(ans+(xx*1LL*(fr[xx]-tmp[xx])))%mod;
        for(auto kk:dv[xx])
          tmp[kk]=(tmp[kk]+(fr[xx]-tmp[xx])+mod)%mod;
      }
      for(int k=dv[x].size()-1;k>=0;k--)
      {
        int xx=dv[x][k];
        for(auto kk:dv[xx])
          tmp[kk]=0;
      }
    }
    for(int j=1;j<=m;j++)
    {
      for(auto xx:dv[arr[1][j]])
        fr[xx]++;
    }
  }
  cout<<ans<<endl;
  return 0;
}