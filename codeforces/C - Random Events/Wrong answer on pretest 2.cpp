/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/11/2020 21:08                        
*  solution_verdict: Wrong answer on pretest 2               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/1461/problem/C
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
const int N=1e6;
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
     int ls=n;
    for(int i=n;i>=1;i--)
    {
      if(a[i]==i)ls--;
      else break;
    }
    if(ls==0)
    {
      cout<<1<<endl;continue;
    }
    double p=1.0;
    for(int i=1;i<=m;i++)
    {
      int id;double d;cin>>id>>d;
      if(id>=ls)p*=(1.0-d);
    }
    cout<<setprecision(10)<<fixed<<(1.0-p)<<endl;
  }
  return 0;
}