/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/10/2020 22:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 8000 KB                              
*  problem: https://codeforces.com/contest/1427/problem/D
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
const int N=1e6,inf=1e9;
int a[N+2],b[N+2],n;
bool ck(int n)
{
  int f=1;
  for(int i=2;i<=n;i++)
    if(a[i]<a[i-1])f=0;
  return f;
}
void doIt(vector<int>v)
{
  int sz=0;
  for(auto x:v)sz+=x;//cout<<"*"<<sz<<endl;
  assert(sz==n);
  vector<pair<int,int> >tmp;
  int ls=0;
  for(auto x:v)
  {
    tmp.push_back({ls+1,ls+x});
    ls+=x;
  }
  reverse(tmp.begin(),tmp.end());
  int id=0;
  for(auto x:tmp)
  {
    for(int i=x.first;i<=x.second;i++)
      b[++id]=a[i];
  }
  for(int i=1;i<=n;i++)a[i]=b[i];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  vector<vector<int> >ans;
  for(int i=1;i<=n;i++)
  {
    if(ck(n))break;vector<int>v;
    if(i%2)
    {
      int cnt=0,id;
      for(int j=1;j<=n;j++)if(a[j]==i)id=j;

      if(id>1)v.push_back(id-1);
      for(int j=id;j<=n;j++)
      {
        if(a[j]<i)break;
        cnt++;
      }
      v.push_back(cnt);
      for(int j=1;j<i;j++)v.push_back(1);
    }
    else
    {
      int cnt=0,id;
      for(int j=1;j<=n;j++)if(a[j]==i)id=j;

      for(int j=1;j<i;j++)v.push_back(1);
      v.push_back(id-(i-1));
      if(n-id)v.push_back(n-id);
    }
    if(v.size()==1)continue;
    doIt(v);ans.push_back(v);
  }
  assert(ck(n));assert(ans.size()<=n);
  cout<<ans.size()<<endl;
  for(auto x:ans)
  {
    cout<<x.size()<<" ";
    for(auto z:x)cout<<z<<" ";
      cout<<endl;
  }
  return 0;
}