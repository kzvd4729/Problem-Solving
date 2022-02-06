/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/10/2020 16:54                        
*  solution_verdict: Wrong answer on test 35                 language: GNU C++17                               
*  run_time: 639 ms                                          memory_used: 25400 KB                             
*  problem: https://codeforces.com/contest/1167/problem/F
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=5e5;
const int mod=1e9+7;
int a[N+2],b[N+2];
void addA(int id,int vl)
{
  for( ;id<=N;id+=id&-id)a[id]=(a[id]+vl)%mod;
}
int getA(int id)
{
  int ret=0;
  for( ;id>0;id-=id&-id)ret=(ret+a[id])%mod;
  return ret;
}
void addB(int id,int vl)
{
  for( ;id>0;id-=id&-id)b[id]=(b[id]+vl)%mod;
}
int getB(int id)
{ 
  int ret=0;
  for( ;id<=N;id+=id&-id)ret=(ret+b[id])%mod;
  return ret;
}
int aa[N+2];map<int,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i],mp[aa[i]]=i;
   for(int i=1;i<=n;i++)addA(i,1);
   int ans=0;
  for(auto x:mp)
  {
    int id=x.second;
    ans=(ans+(1LL*x.first*(1LL*(n-id+1)*getA(id))%mod)%mod)%mod;
    ans=(ans+(1LL*x.first*(1LL*id*getB(id))%mod)%mod)%mod;
     addA(id+1,id);addB(id-1,n-id+1);
  }
  cout<<ans<<endl;
  return 0;
}