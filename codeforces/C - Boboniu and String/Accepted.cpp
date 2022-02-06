/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/17/2020 17:40                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 93 ms                                           memory_used: 6200 KB                              
*  problem: https://codeforces.com/contest/1394/problem/C
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
const int N=1e6,inf=1e9;
int cal(int a,int b,int c,int d)
{
  int d1=a-c,d2=b-d;
  if((d1<=0&&d2<=0)||(d1>=0&&d2>=0))
  {
    d1=abs(d1),d2=abs(d2);
    return d1+d2-min(d1,d2);
  }
  return abs(d1)+abs(d2);
}
vector<pair<int,int> >v;int ls;
int cal(int md)
{
  int lo=0,hi=1e6,md1,md2;
  while(hi-lo>10)
  {
    md1=(lo+lo+hi)/3;md2=(lo+hi+hi)/3;
     int mx1=0;
    for(int j=0;j<v.size();j++)
      mx1=max(mx1,cal(v[j].first,v[j].second,md,md1));
    int mx2=0;
    for(int j=0;j<v.size();j++)
      mx2=max(mx2,cal(v[j].first,v[j].second,md,md2));
    if(mx1<=mx2)hi=md2;else lo=md1;
  }
  int ret=inf;
  for(int md1=lo;md1<=hi;md1++)
  {
    int mx1=0;
    for(int j=0;j<v.size();j++)
      mx1=max(mx1,cal(v[j].first,v[j].second,md,md1));
    if(mx1<ret)ret=mx1,ls=md1;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;int a=0,b=0;
    for(auto x:s)if(x=='B')a++;else b++;
    v.push_back({a,b});
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
    int lo=0,hi=1e6,md1,md2;
  while(hi-lo>10)
  {
    md1=(lo+lo+hi)/3;md2=(lo+hi+hi)/3;
    if(cal(md1)<=cal(md2))hi=md2;
    else lo=md1;
  }
  //for(int i=0;i<=10;i++)cout<<cal(i)<<endl;
  int ans=inf,ca,cb;
  for(int md=lo;md<=hi;md++)
  {
    if(cal(md)<=ans)ans=cal(md),ca=md,cb=ls;
  }
  assert(ca+cb);
  cout<<ans<<endl;
  for(int i=1;i<=ca;i++)cout<<'B';
  for(int i=1;i<=cb;i++)cout<<'N';
  cout<<endl;
  return 0;
}