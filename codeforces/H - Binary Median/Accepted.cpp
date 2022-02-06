/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/26/2020 19:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4000 KB                              
*  problem: https://codeforces.com/contest/1360/problem/H
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
#define long long long
using namespace std;
const int N=60;
long ret(string s)
{
  long a=0;
  for(int i=0;i<s.size();i++)
    a=a*2+s[i]-'0';
  return a;
}
long p(long x,long m)
{
  //cout<<x<<endl;
  for(int i=m-1;i>=0;i--)
  {
    bool z=(x&(1LL<<i));
    cout<<z;
  }
  cout<<endl;
}
void solve()
{
  int n,m;cin>>n>>m;vector<long>v;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;v.push_back(ret(s));
    //cout<<"*"<<ret(s)<<endl;
  }
  sort(v.begin(),v.end());
  long tt=(1LL<<m);
  for(long md=max(0LL,tt/2-200);md<=min(tt-1,tt/2+200);md++)
  {
    //if(md!=3)continue;
    if(binary_search(v.begin(),v.end(),md))continue;
    int sm=lower_bound(v.begin(),v.end(),md)-v.begin();
    int bg=n-sm;
    long b=tt-1-md-bg,a=md-sm;
    if(a==b||a+1==b){p(md,m);return;}
  }
  assert(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}