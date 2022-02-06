/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/13/2020 12:42                        
*  solution_verdict: Runtime error on test 6                 language: GNU C++14                               
*  run_time: 264 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/755/problem/D
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
int bit[N+2];
void upd(int x)
{
  for( ;x<=N;x+=x&-x)bit[x]++;
}
int get(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)ret+=bit[x];
  return ret;
}
int get(int lo,int hi)
{
  return get(hi)-get(lo-1);
}
int vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;long ans=1;
   int p=1;
  while(true)
  {
    if(vs[p])break;vs[p]=1;
    if(k+k<=n)
    {
      if(p+k>n)
      {
        int nx=p+k-n;
        int g=get(p+1,n)+get(1,nx-1);
        ans+=g+1;upd(p);upd(nx);
        p=nx;
      }
      else
      {
        int g=get(p+1,p+k-1);
        ans+=g+1;upd(p);upd(p+k);
        p=p+k;
      }
    }
    else
    {
      if(p+k>n)
      {
        int nx=p+k-n;
        int g=get(nx+1,p-1);
        ans+=g+1;upd(p);upd(nx);
        p=nx;
      }
      else
      {
        int g=get(p+k+1,n)+get(1,p-1);
        ans+=g+1;upd(p);upd(p+k);
        p+=p+k;
      }
    }
    cout<<ans<<" ";
  }
  cout<<endl;
  return 0;
}