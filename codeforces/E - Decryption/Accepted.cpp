/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/22/2020 13:22                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 77 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1419/problem/E
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
vector<int>v;
int lcm(int a,int b)
{
  return 1LL*a*b/__gcd(a,b);
}
void tryCatch(int x,vector<int>v)
{
  if(v.size()<3)
  {
    for(auto x:v)cout<<x<<" ";cout<<endl;
    cout<<0<<endl;return ;
  }
  for(auto x:v)cout<<x<<" ";cout<<endl;
  cout<<(__gcd(v[0],v[1])==1)<<endl;
}
void solve(int x)
{
  v.clear();int sq=sqrt(x+1);
  for(int i=2;i<=sq;i++)
  {
    if(x%i)continue;v.push_back(i);
    if(i!=x/i)v.push_back(x/i);
  }
  v.push_back(x);
  sort(v.begin(),v.end());
   if(v.size()<=3){tryCatch(x,v);return;}
    vector<int>a;a.push_back(v[0]);map<int,int>mp;mp[v[0]]=1;
  for(int i=1;i<v.size();i++)
  {
    if(mp[v[i]])continue;
    if(__gcd(v[i],a.back())==1)
    {
      int lc=lcm(v[i],a.back());
      a.push_back(lc);a.push_back(v[i]);
      assert(mp[lc]==0);assert(mp[v[i]]==0);
      mp[lc]=1;mp[v[i]]=1;
    }
    else
    {
      a.push_back(v[i]);assert(mp[v[i]]==0);mp[v[i]]=1;
    }
  }
  int f=1;
  if(__gcd(a[0],a.back())==1)
  {
    f=0;int s=a.size()-1;
    for(int i=1;i<a.size()-1;i++)
    {
      swap(a[i],a[a.size()-1]);
      if(__gcd(a[i-1],a[i])>1&&__gcd(a[i+1],a[i])>1&&__gcd(a[s],a[0])>1&&__gcd(a[s],a[s-1])>1)
      {
        f=1;break;
      }
      swap(a[i],a[a.size()-1]);
    }
  }
  assert(f);
  //for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<endl;
  if(a.size()!=v.size())assert(0);
  for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<endl;
    cout<<0<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int x;cin>>x;solve(x);
  }
   return 0;
}