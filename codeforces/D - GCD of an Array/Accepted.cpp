/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/06/2021 21:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 451 ms                                          memory_used: 50500 KB                             
*  problem: https://codeforces.com/contest/1493/problem/D
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
#include<random>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e5,inf=1e9,mod=1e9+7;
 vector<int>fc[N+2];int vs[N+2];
void factorize()
{
  for(int i=2;i<=N;i++)
  {
    if(vs[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      vs[j]=1;fc[j].push_back(i);
    }
  }
}
int a[N+2];
map<int,int>mp[N+2],cr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  factorize();
   int n,q;cin>>n>>q;
  long ans=1;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];int nm=a[i];
     for(auto x:fc[a[i]])
    {
      int cnt=0;
      while((nm%x)==0)
      {
        cnt++;nm/=x;
        int now=++mp[x][cnt];
         if(now==n)ans=(ans*x)%mod;
      }
      cr[i][x]=cnt;
    }
  }
  while(q--)
  {
    int id,vl;cin>>id>>vl;
    int nm=vl;
    for(auto x:fc[vl])
    {
      int cnt=cr[id][x];
      while((nm%x)==0)
      {
        cnt++;nm/=x;
        int now=++mp[x][cnt];
         if(now==n)ans=(ans*x)%mod;
      }
      cr[id][x]=cnt;
    }
    cout<<ans<<'\n';
  }
  return 0;
}