/****************************************************************************************
*  @author: kzvd4729                                         created: May/23/2020 10:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1354/problem/A
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
const int N=2e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long a,b,c,d;cin>>a>>b>>c>>d;
    if(b>=a)cout<<b<<'\n';
    else
    {
      if(c<=d)cout<<-1<<'\n';
      else
      {
        long cy=(a-b+c-d-1)/(c-d);
        cout<<b+cy*c<<'\n';
      }
    }
  }
   return 0;
}