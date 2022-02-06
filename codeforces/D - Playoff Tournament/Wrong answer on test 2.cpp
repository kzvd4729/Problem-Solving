/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/04/2021 21:53                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++17 (64)                          
*  run_time: 15 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1535/problem/D
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
 string s;int n;
 int sg[4*N+8];
 void dfs(int nd,int lo,int hi)
{
  if(lo+1==hi)
  {
    if(s[n-nd]=='?')sg[nd]=2;
    else sg[nd]=1;
     return ;
  }
   int md=(lo+hi)/2;
  dfs(nd*2+1,lo,md);
  dfs(nd*2,md+1,hi);
   int l=sg[nd*2+1],r=sg[nd*2];
   if(s[n-nd]=='?')sg[nd]=l+r;
  else if(s[n-nd]=='0')sg[nd]=l;
  else sg[nd]=r;
 }
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int k;cin>>k>>s;n=s.size();
   dfs(1,1,(1<<k));
   int q;cin>>q;
  while(q--)
  {
    int id;char c;cin>>id>>c;id--;
    s[id]=c;
     int nd=n-id;
     while(nd)
    {
      int id=n-nd;
      if(id<k)
      {
        if(s[n-nd]=='?')sg[nd]=2;
        else sg[nd]=1;
      }
      else
      {
        int l=sg[nd*2+1],r=sg[nd*2];
         if(s[n-nd]=='?')sg[nd]=l+r;
        else if(s[n-nd]=='0')sg[nd]=l;
        else sg[nd]=r;
      }
      nd/=2;
    }
    cout<<sg[1]<<'\n';
  }
     return 0;
}