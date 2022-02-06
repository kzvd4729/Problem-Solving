/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2021 18:59                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 62 ms                                           memory_used: 1200 KB                              
*  problem: https://codeforces.com/contest/1508/problem/A
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
 string s[4+2];int p[3+2],cnt[3+2];
char choose()
{
  memset(cnt,0,sizeof cnt);
   for(int i=1;i<=3;i++)
  {
    if(p[i]==(int)s[i].size())continue;
    cnt[s[i][p[i]]-'0']++;
  }
  char ret='0';
   if(cnt[0]+cnt[1]==0)return ret;
  else if(cnt[0]+cnt[1]==3)
  {
    if(cnt[1]>=2)ret='1';
  }
  else
  {
    int mn=-1;
    for(int i=1;i<=3;i++)
    {
      if(p[i]==(int)s[i].size())continue;
      if(p[i]>mn)mn=p[i],ret=s[i][p[i]];
    }
  }
  for(int i=1;i<=3;i++)
  {
    if(p[i]==(int)s[i].size())continue;
    if(s[i][p[i]]==ret)p[i]++;
  }
  return ret;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    memset(p,0,sizeof p);
    int n;cin>>n;
    for(int i=1;i<=3;i++)cin>>s[i];
     for(int i=1;i<=3*n;i++)cout<<choose();
      cout<<endl;
   }
  return 0;
}