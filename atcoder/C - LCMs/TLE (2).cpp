/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-11-19 19:25:46                      
*  solution_verdict: TLE                                     language: C++14 (GCC 5.4.1)                       
*  run_time: 2109 ms                                         memory_used: 134272 KB                            
*  problem: https://atcoder.jp/contests/agc038/tasks/agc038_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=998244353;
vector<int>dd[N+2];
void divi(void)
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)
      dd[j].push_back(i);
  }
  for(int i=1;i<=N;i++)
    reverse(dd[i].begin(),dd[i].end());
}
int aa[N+2];long sum[N+2],tmp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  divi();int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   for(int i=1;i<=n;i++)
  {
    for(auto x:dd[aa[i]])
     sum[x]+=aa[i];
  }
  int ans=0;
  for(int i=1;i<=n;i++)
  {
   for(auto x:dd[aa[i]])sum[x]-=aa[i],tmp[x]=0;
    int x=aa[i];
    for(int j=0;j<dd[x].size();j++)
    {
      long sm=sum[dd[x][j]];
      for(int k=0;k<j;k++)
        if(dd[x][k]%dd[x][j]==0)sm-=tmp[dd[x][k]];
      tmp[dd[x][j]]=sm;
       //cout<<"**"<<(x/dd[x][j])*sm<<endl;
       ans=(ans+1LL*(x/dd[x][j])*(sm%mod))%mod;
    }
  }
  cout<<ans<<endl;
  return 0;
}