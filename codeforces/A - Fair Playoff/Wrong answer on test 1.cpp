/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/04/2021 20:58                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++17 (64)                          
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1535/problem/A
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
  long cal(string s)
{
  long ret=0,cnt=0;
  for(auto x:s)
  {
    if(x=='0')cnt++;
    else
    {
      ret+=(cnt*(cnt+1))/2;
      cnt=0;
    }
  }
  ret+=(cnt*(cnt+1))/2;
   return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    string s,a;cin>>s;a=s;
     for(int i=0;i<(int)s.size();i++)
    {
      if(s[i]=='?')
      {
        a[i]='0';continue;
      }
       if(s[i]=='0')
      {
        if(i%2==0)a[i]='0';
        else a[i]='1';
      }
      if(s[i]=='1')
      {
        if(i%2==0)a[i]='1';
        else a[i]='0';
      }
    }
    long ans=cal(a);
     for(int i=0;i<(int)s.size();i++)
    {
      if(s[i]=='?')
      {
        a[i]='0';continue;
      }
       if(s[i]=='0')
      {
        if(i%2==0)a[i]='1';
        else a[i]='0';
      }
      if(s[i]=='1')
      {
        if(i%2==0)a[i]='0';
        else a[i]='1';
      }
    }
     ans+=cal(a);
      for(int i=0;i<(int)s.size();i++)
    {
      if(s[i]=='?')
      {
        a[i]='0';continue;
      }
       a[i]='1';
    }
     cout<<ans-cal(a)<<'\n';
  }  
  return 0;
}