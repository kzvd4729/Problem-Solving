/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-03 23:48:09                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 409 ms                                          memory_used: 102060 KB                            
*  problem: https://atcoder.jp/contests/jsc2021/tasks/jsc2021_e
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
const int N=1e6,inf=1e9;
const int mod=1e9+7;
  int n,len;string s;
vector<int>ad[N+2];
bool dfs(int lo,int hi,int k)
{
  if(k==0)
  {
    len=hi-lo+1;
    return lo!=hi;
  }
  if(lo>hi)return false;
   int md=(lo+hi)/2,ret;
  if((hi-lo+1)%2==0)
  {
    for(int i=lo;i<=md;i++)
    {
      int j=hi-(i-lo);
      ad[i].push_back(j);ad[j].push_back(i);
    }
    ret=dfs(lo,md,k-1)&dfs(md+1,hi,k-1);
  }
  else
  {
    for(int i=lo;i<=md-1;i++)
    {
      int j=hi-(i-lo);
      ad[i].push_back(j);ad[j].push_back(i);
    }
    ret=dfs(lo,md-1,k-1)&dfs(md+1,hi,k-1);
  }
  return ret;
}
 int vs[N+2];vector<int>cnt;
void dfs(int nd)
{
  if(vs[nd])return ;vs[nd]=1;
  cnt[s[nd]-'a']++;
   for(auto x:ad[nd])dfs(x);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>s;
   if(dfs(0,(int)s.size()-1,n)==0)cout<<"impossible"<<endl,exit(0);
   vector<int>p;int un=0;vector<vector<int> >str;
  for(int i=0;i<(int)s.size();i++)
  {
    if(vs[i])continue;cnt.assign(26,0);
    dfs(i);//cout<<i<<endl;
     int mx=0,id;
    for(int j=0;j<26;j++)if(cnt[j]>mx)mx=cnt[j],id=j;
     un+=mx;if(i<len)p.push_back(id),str.push_back(cnt);
  }
   if((int)p.size()==0)
  {
    cout<<s.size()-un<<endl,exit(0);
  }
   vector<int>q=p;
  reverse(p.begin(),p.end());
   if(p==q)
  {
    int mn=inf;
    for(int i=0;i<(int)p.size();i++)
    {
      if((int)p.size()%2 && i==(int)p.size()/2)continue;
       vector<int>cnt=str[i];
      for(int j=0;j<26;j++)
      {
        if(j==p[i])continue;
        mn=min(mn,cnt[p[i]]-cnt[j]);
      }
    }
    un-=mn;
  }
  cout<<(int)s.size()-un<<endl;
   return 0;
}