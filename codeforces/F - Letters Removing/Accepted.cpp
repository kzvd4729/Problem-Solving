/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/21/2020 16:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 17700 KB                             
*  problem: https://codeforces.com/contest/899/problem/F
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
const int N=2e5;
int con(char c)
{
  if(c>='a'&&c<='z')return 10+c-'a';
  if(c>='A'&&c<='Z')return 36+c-'A';
  return c-'0';
}
int bit[N+2];
void add(int x)
{
  for( ;x<=N;x+=x&-x)bit[x]++;
}
int get(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)ret+=bit[x];
  return ret;
}
vector<int>vv[N+2];set<int>st[N+2];
int f[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;string s;cin>>s;
   for(int i=1;i<=n;i++)st[con(s[i-1])].insert(i),vv[con(s[i-1])].push_back(i);
  for(int i=0;i<62;i++)sort(vv[i].begin(),vv[i].end());
   while(m--)
  {
    int l,r;char c;cin>>l>>r>>c;int x=con(c);
    int lo=0,hi=vv[x].size(),md;
    while(lo<hi)
    {
      md=(lo+hi)/2;
      if(vv[x][md]-get(vv[x][md])>=l)hi=md;else lo=md+1;
    }
    if(lo==(int)vv[x].size())continue;
    auto it=st[x].lower_bound(vv[x][lo]);
    vector<int>buf;
    while(it!=st[x].end())
    {
      if(*it-get(*it)>r)break;
      buf.push_back(*it);//add(*it);
      it++;
    }
    for(auto z:buf)st[x].erase(z),add(z);
  }
  for(int i=0;i<62;i++)
  {
    for(auto x:st[i])f[x]=1;
  }
  for(int i=1;i<=n;i++)if(f[i])cout<<s[i-1];
    cout<<endl;
  return 0;
}