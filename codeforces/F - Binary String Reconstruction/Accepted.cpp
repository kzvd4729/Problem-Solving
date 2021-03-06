/****************************************************************************************
*  @author: * kzvd4729                                       created: May/09/2020 21:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1352/problem/F
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
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int a,b,c;cin>>a>>b>>c;
    if(!b)
    {
      if(a>0&&c>0)assert(0);
      if(a>0)
      {
        for(int i=1;i<=a+1;i++)cout<<0;
          cout<<"\n";
      }
      else
      {
        for(int i=1;i<=c+1;i++)cout<<1;
          cout<<"\n";
      }
      continue;
    }
    if(!a)
    {
      for(int i=1;i<=c+1;i++)cout<<1;
      int f=0;
      for(int i=1;i<=b;i++)
      {
        cout<<f;f^=1;
      }
      cout<<"\n";continue;
    }
    if(!c)
    {
      for(int i=1;i<=a+1;i++)cout<<0;
      int f=1;
      for(int i=1;i<=b;i++)
      {
        cout<<f;f^=1;
      }
      cout<<"\n";continue;
    }
    int f=0;
    for(int i=1;i<=b;i++)
    {
      cout<<f;f^=1;
    }
    if(f)
    {
      for(int i=1;i<=a;i++)cout<<0;
      for(int i=1;i<=c+1;i++)cout<<1;
        cout<<"\n";
    }
    else
    {
      for(int i=1;i<=c;i++)cout<<1;
      for(int i=1;i<=a+1;i++)cout<<0;
        cout<<"\n";
    }
  }
  return 0;
}