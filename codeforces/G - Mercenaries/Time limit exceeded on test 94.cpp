/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/29/2020 14:07                        
*  solution_verdict: Time limit exceeded on test 94          language: GNU C++17                               
*  run_time: 7000 ms                                         memory_used: 56700 KB                             
*  problem: https://codeforces.com/contest/1400/problem/G
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=3e5,mod=998244353;
int fac[N+2];
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
void init()
{
  fac[0]=1;
  for(int i=1;i<=N;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
}
int ncr(int n,int r)
{
  if(r>n||r<0)return 0;
  int ret=(1LL*fac[n]*big(fac[r],mod-2))%mod;
  return (1LL*ret*big(fac[n-r],mod-2))%mod;
}
int sm[40+2][N+2],a[N+2],b[N+2],c[N+2],l[N+2],r[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
  for(int i=1;i<=n;i++)c[a[i]]++,c[b[i]+1]--;
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    c[i]+=c[i-1];
    ans=(ans+ncr(c[i],i))%mod;
  }
  for(int i=2;i<=40;i++)
  {
    for(int j=i;j<=N;j++)
    {
      sm[i][j]=(sm[i][j-1]+ncr(c[j]-i,j-i))%mod;
      //cout<<j<<" && "<<c[j]-i<<" "<<j-i<<endl;
    }
  }
  for(int i=0;i<m;i++)cin>>l[i]>>r[i];
  for(int i=1;i<(1<<m);i++)
  {
    vector<int>v;
    for(int j=0;j<m;j++)
    {
      if(!(i&(1<<j)))continue;
      v.push_back(l[j]);v.push_back(r[j]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
     int L=v.size(),R=n;
    for(auto x:v)L=max(L,a[x]),R=min(R,b[x]);
    if(L>R)continue;
    //cout<<L<<" (( "<<R<<endl;
    int ad=(sm[v.size()][R]-sm[v.size()][L-1]+mod)%mod;
    if(__builtin_popcount(i)%2)ad=(ad*-1+mod)%mod;
    ans=(ans+ad)%mod;
  }
  cout<<(ans+mod)%mod<<endl;
  return 0;
}