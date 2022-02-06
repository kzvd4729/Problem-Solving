/****************************************************************************************
*  @author: * kzvd4729                                       created: May/14/2020 20:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1353/problem/A
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
    int n,m;cin>>n>>m;
    if(n==1){cout<<0<<endl;continue;}
    else if(n==2){cout<<m<<endl;continue;}
    else cout<<m+m<<endl;
  }
    return 0;
}