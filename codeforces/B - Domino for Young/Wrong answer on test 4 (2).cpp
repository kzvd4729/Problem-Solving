/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/28/2021 23:05                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 5200 KB                              
*  problem: https://codeforces.com/contest/1268/problem/B
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
const int N=3e5,inf=1e9,mod=998244353;
   /*
range update range sum.
*/
long bit[2][N+2];
void upd(int x,long ml,long sm)
{
  for( ;x<=N;x+=(x&-x))
    bit[0][x]+=ml,bit[1][x]+=sm;
}
long get(int x)
{
  long ml=0,sm=0,bg=x;
  for( ;x>0;x-=(x&-x))
    ml+=bit[0][x],sm+=bit[1][x];
  return ml*bg+sm;
}
long getRange(int lo,int hi)
{
  return get(hi)-get(lo-1);
}
void addRange(int lo,int hi,long vl)
{
  upd(lo,vl,-vl*(lo-1));
  upd(hi,-vl,vl*hi);
}
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;vector<int>v;long tt=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;tt+=x; addRange(1,x,1);
     if((int)v.size()==0)
    {
      if(x%2)v.push_back(x);
    }
    else
    {
      if(x%2==0)
      {
        if(v.back()%2==0);
        else v.push_back(x);
      }
      else
      {
        if(v.back()%2==0)v.push_back(x);
        else v.pop_back();
      }
    }
  }
  n=v.size();int ws=(n+1)/2;
   long ans=(tt-ws)/2;
    v.clear();
  for(int i=1;i<=N;i++)
  {
    int x=getRange(i,i);
    if((int)v.size()==0)
    {
      if(x%2)v.push_back(x);
    }
    else
    {
      if(x%2==0)
      {
        if(v.back()%2==0);
        else v.push_back(x);
      }
      else
      {
        if(v.back()%2==0)v.push_back(x);
        else v.pop_back();
      }
    }
  }
   n=v.size();ws=(n+1)/2;
  ans=min(ans,(tt-ws)/2);
   cout<<ans<<endl;
   return 0;
}