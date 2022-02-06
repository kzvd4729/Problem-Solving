/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/14/2020 14:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 560 ms                                          memory_used: 83800 KB                             
*  problem: https://codeforces.com/contest/528/problem/B
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
const int N=5e5,inf=1e9+1;
int x[N+2],w[N+2];
 const int sz=1e7;//more size better
int key[sz+2],val[sz+2];//can be any data type
static inline int h(long x){return((x^179)*7)%sz;}
void init()
{
  memset(key,-1,sizeof key);//-1 is invalid
  memset(val,-1,sizeof val);
}
void add(int x,int y)
{
  int k=h(x);
  while(key[k]!=-1&&key[k]!=x)k=(k+1)%sz;//first non-taken index
  key[k]=x,val[k]=max(val[k],y);
}
int get(long x)
{
  for(int k=h(x);key[k]!=-1;k=(k+1)%sz)
    if(key[k]==x)return val[k];
  return -1;
}
void updx(int x,int vl)
{
  for( ;x>0;x-=x&-x)add(x,vl);
}
int getx(long x)
{
  int ret=0;
  for( ;x<=inf+inf;x+=x&-x)ret=max(ret,get(x));
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();
  int n;cin>>n;vector<pair<int,int> >v(n);
  for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second,v[i].first+=inf;
  sort(v.begin(),v.end());int ans=0;
  for(int i=n-1;i>=0;i--)
  {
    int g=getx(v[i].first*1LL+v[i].second)+1;
    ans=max(ans,g);updx(v[i].first-v[i].second,g);
  }
  cout<<ans<<endl;
  return 0;
}