/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-05 16:38:13                      
*  solution_verdict: WA                                      language: C++ (GCC 9.2.1)                         
*  run_time: 105 ms                                          memory_used: 7764 KB                              
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
void dfs(vector<int>v)
{
  if(isOk(v)==0)return ;
   vector<int>a,b;
  for(int i=0;i<(int)v.size();i++)
  {
    a.push_back(v[i]/2);b.push_back(v[i]-a[i]);  
  }
  if(isOk(a) && isOk(b))
  {
    dfs(a);dfs(b);
    return ;
  }
  ans.push_back(v);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>s;vector<int>a(n+1);
  for(int i=0;i<n+1;i++)cin>>a[i];
   dfs(a);
   cout<<(int)ans.size()<<endl;
  for(auto x:ans)
  {
    for(auto z:x)cout<<z<<" ";cout<<endl;
  }
      return 0;
}