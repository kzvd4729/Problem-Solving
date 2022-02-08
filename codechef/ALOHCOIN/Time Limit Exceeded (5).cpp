/****************************************************************************************
*  @author: kzvd4729                                         created: 12-06-2021 22:33:29                      
*  solution_verdict: Time Limit Exceeded                     language: C++14                                   
*  run_time: 1.01 sec                                        memory_used: 175M                                 
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
int xx,yy;
unordered_map<int,long>bit[N+2],bit2[N+2];
void add(int x,int y,int vl)
{
  for( ;x<=xx;x+=x&-x)
  {
    int z=y;
    for( ;z<=yy;z+=z&-z)bit[x][z]+=vl;
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
  for( ;x<=xx;x+=x&-x)
  {
    int z=y;
    for( ;z<=yy;z+=z&-z)ret+=bit2[x][z];
  }
  return ret;
}
int x[N+2],y[N+2],vl[N+2];
int compressx(int n)
{
  vector<int>v;
  for(int i=1;i<=n;i++)v.push_back(x[i]);
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  map<int,int>mp;
  for(int i=0;i<v.size();i++)mp[v[i]]=i+1;
  for(int i=1;i<=n;i++)x[i]=mp[x[i]];
  return v.size();
}
int compressy(int n)
{
  vector<int>v;
  for(int i=1;i<=n;i++)v.push_back(y[i]);
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  map<int,int>mp;
  for(int i=0;i<v.size();i++)mp[v[i]]=i+1;
  for(int i=1;i<=n;i++)y[i]=mp[y[i]];
  return v.size();
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
      cin>>x[i]>>y[i]>>vl[i];
    }
    xx=compressx(n),yy=compressy(n);
        for(int i=1;i<=n;i++)
    {
      add(x[i],y[i],vl[i]);add2(x[i],y[i],vl[i]);
      cout<<get2(x[i],y[i])-get(x[i]-1,y[i]-1)<<'\n';
    }
  }
  return 0;
}