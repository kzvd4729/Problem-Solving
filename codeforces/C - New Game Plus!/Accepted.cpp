/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/29/2020 16:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 35800 KB                             
*  problem: https://codeforces.com/contest/1456/problem/C
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
const int N=1e6;
long n,sz[N+2],a[N+2],cal[N+2],sm[N+2];
void pre()
{
  sort(a+1,a+n+1);
  for(int i=n;i>=1;i--)
  {
    sm[i]=sm[i+1]+a[i];
    cal[i]=cal[i+1]+sm[i];
  }
  //for(int i=1;i<=n;i++)cout<<cal[i]<<" ";cout<<endl;
}
long ret(int tk,int sz)
{
  if(sz==0)return cal[tk+2];
  else return cal[tk+1]+sm[tk+1]*(sz-1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int k;cin>>n>>k;
  vector<int>ps,ng;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;a[i]=x;
    if(x>=0)ps.push_back(x);
    else ng.push_back(x);
  }
  pre();
  sort(ps.begin(),ps.end());
  sort(ng.begin(),ng.end());
   long pr=-2e18,ans=0,sg=k+1,mx=0;
   for(int i=0;i<ng.size();i++)
  {
    int id=i%sg;
    pr=max(pr,ans+ret(i,mx));
     ans+=(ng[i]*sz[id]);
    sz[id]++;mx=max(mx,sz[id]);
  }
  pr=max(pr,ans+ret((int)ng.size(),mx));
  cout<<pr<<endl;
  return 0;
}