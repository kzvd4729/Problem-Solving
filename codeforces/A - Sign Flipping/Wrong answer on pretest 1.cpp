/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/04/2020 20:51                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1375/problem/A
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
#include<stack>
#include<deque>
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
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<a[1]<<" ";
    for(int i=2;i<=n/2+1;i++)
    {
      if(a[i]-a[i-1]>0)a[i]*=-1;
      cout<<a[i]<<" ";
    }
    for(int i=n/2+2;i<=n;i++)
    {
      if(a[i]-a[i-1]<0)a[i]*=-1;
      cout<<a[i]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}