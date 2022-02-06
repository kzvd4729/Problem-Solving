/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/04/2020 19:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1453/problem/A
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
int f[100+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int a,b;cin>>a>>b;
    memset(f,0,sizeof f);
    for(int i=1;i<=a;i++)
    {
      int x;cin>>x;f[x]++;
    }
    for(int i=1;i<=b;i++)
    {
      int x;cin>>x;f[x]++;
    }
    int cnt=0;
    for(int i=1;i<=100;i++)
      cnt+=(f[i]>=2);
    cout<<cnt<<endl;
  }
    return 0;
}