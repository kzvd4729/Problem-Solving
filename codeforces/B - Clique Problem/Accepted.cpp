/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/14/2020 14:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1372 ms                                         memory_used: 88500 KB                             
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
map<int,int>bit;
void upd(int x,int vl)
{
  for( ;x>0;x-=x&-x)bit[x]=max(bit[x],vl);
}
int get(long x)
{
  int ret=0;
  for( ;x<=inf+inf;x+=x&-x)ret=max(ret,bit[x]);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<pair<int,int> >v(n);
  for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second,v[i].first+=inf;
  sort(v.begin(),v.end());int ans=0;
  for(int i=n-1;i>=0;i--)
  {
    int g=get(v[i].first*1LL+v[i].second)+1;
    ans=max(ans,g);upd(v[i].first-v[i].second,g);
  }
  cout<<ans<<endl;
  return 0;
}