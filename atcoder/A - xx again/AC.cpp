/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-05 16:57:12                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 190 ms                                          memory_used: 17220 KB                             
*  problem: https://atcoder.jp/contests/agc053/tasks/agc053_a
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
const int N=1e6,inf=1e9,mod=1e9+7;
 int n;string s;
 bool isOk(vector<int>v)
{
  for(int i=1;i<(int)v.size();i++)
  {
    if(v[i]==v[i-1])return false;
    if(v[i-1]<v[i] && s[i-1]=='>')return false;
    if(v[i-1]>v[i] && s[i-1]=='<')return false;
  }
  return true;
}
vector<vector<int> >ans;
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>s;vector<int>a(n+1);
  for(int i=0;i<n+1;i++)cin>>a[i];
   int lo=1,hi=10000,md;
  while(lo<=hi)
  {
    int md=(lo+hi)/2;
     vector<vector<int> >v(md);int f=1;
    for(int i=0;i<n+1;i++)
    {
      for(int j=0;j<md;j++)
      {
        v[j].push_back(a[i]/md);
      }
      int ex=a[i]%md;
      for(int j=0;j<ex;j++)v[j][i]++;
    }
     for(int j=0;j<md;j++)f&=isOk(v[j]);
    if(f){ans=v;lo=md+1;}
    else hi=md-1;
  }  
   cout<<(int)ans.size()<<endl;
  for(auto x:ans)
  {
    for(auto z:x)cout<<z<<" ";cout<<endl;
  }
      return 0;
}