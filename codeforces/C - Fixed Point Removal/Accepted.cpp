/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/07/2020 00:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 514 ms                                          memory_used: 13200 KB                             
*  problem: https://codeforces.com/contest/1404/problem/C
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
const int N=3e5;
int a[N+2],bit[N+2];
void upd(int x)
{
  for( ;x>0;x-=x&-x)bit[x]++;
}
int get(int x)
{
  int ret=0;
  for( ;x<=N;x+=x&-x)ret+=bit[x];
  return ret;
}
vector<pair<int,int> >v[N+2];int ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>a[i],a[i]=i-a[i];
  //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
   for(int i=1;i<=q;i++)
  {
    int l,r;cin>>l>>r;
    l=l+1,r=n-r;v[r].push_back({l,i});
  }
  for(int i=1;i<=n;i++)
  {
    if(a[i]<0)
    {
      for(auto x:v[i])
        ans[x.second]=get(x.first);
      continue;
    }
    if(get(1)<a[i])
    {
      for(auto x:v[i])
        ans[x.second]=get(x.first);
      continue; 
    }
    int lo=1,hi=i,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(get(md)>=a[i])lo=md;else hi=md;
    }
    for(md=hi;md>=lo;md--)
      if(get(md)>=a[i])break;
    upd(md);
     for(auto x:v[i])
      ans[x.second]=get(x.first);
    //cout<<i<<" "<<lo-1<<endl;
  }
  for(int i=1;i<=q;i++)cout<<ans[i]<<" ";cout<<endl;
  return 0;
}