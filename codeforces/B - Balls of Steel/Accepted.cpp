/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/06/2020 20:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1450/problem/B
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
int a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
     int g=0;
    for(int i=1;i<=n;i++)
    {
      int f=1;
      for(int j=1;j<=n;j++)
      {
        if(abs(a[i]-a[j])+abs(b[i]-b[j])>k)f=0;
      }
      g|=f;
    }
    if(g==0)g=-1;cout<<g<<endl;
  } 
  return 0;
}