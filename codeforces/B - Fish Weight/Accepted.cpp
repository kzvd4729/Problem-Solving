/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/24/2020 17:42                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 186 ms                                          memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/297/problem/B
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
const int N=1e5;
int a[N+2],b[N+2];
void ya(){cout<<"YES"<<endl,exit(0);}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;if(n>m)ya();
  for(int i=1;i<=n;i++)cin>>a[i];sort(a+1,a+n+1);
  for(int i=1;i<=m;i++)cin>>b[i];sort(b+1,b+m+1);

  int x=n,y=m;
  for(int i=0;i<n;i++)
  {
    if(a[x]>b[y])ya();
    x--,y--;
  }
  cout<<"NO"<<endl;
  return 0;
}