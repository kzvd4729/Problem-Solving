/****************************************************************************************
*  @author: kzvd4729                                         created: 12-06-2021 22:24:32                      
*  solution_verdict: Time Limit Exceeded                     language: C++14                                   
*  run_time: 1.01 sec                                        memory_used: 229.8M                               
*  problem: https://www.codechef.com/problems/ALOHCOIN
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
const int N=1e6+2,inf=1e9,mod=1e9+7;
const int offset=5e5+1;
unordered_map<int,long>bit[N+2],bit2[N+2];
void add(int x,int y,int vl)
{
  for( ;x<=N;x+=x&-x)
  {
    int z=y;
    for( ;z<=N;z+=z&-z)bit[x][z]+=vl;
  }
}
long get(int x,int y)
{
  long ret=0;
  for( ;x>0;x-=x&-x)
  {
    int z=y;
    for( ;z>0;z-=z&-z)ret+=bit[x][z];
  }
  return ret;
}
void add2(int x,int y,int vl)
{
  for( ;x>0;x-=x&-x)
  {
    int z=y;
    for( ;z>0;z-=z&-z)bit2[x][z]+=vl;
  }
}
long get2(int x,int y)
{
  long ret=0;
  for( ;x<=N;x+=x&-x)
  {
    int z=y;
    for( ;z<=N;z+=z&-z)ret+=bit2[x][z];
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=N;i++)bit[i].clear(),bit2[i].clear();
    for(int i=1;i<=n;i++)
    {
      int x,y,vl;cin>>x>>y>>vl;
      x+=offset,y+=offset;
      add(x,y,vl);add2(x,y,vl);
      cout<<get2(x,y)-get(x-1,y-1)<<'\n';
    }
  }
  return 0;
}