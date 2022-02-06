/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/09/2020 14:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 343 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1244/problem/G
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
   int n;long k,sm=0;cin>>n>>k;
  for(int i=1;i<=n;i++)a[i]=i,b[i]=i,sm+=i;
   if(sm>k)cout<<-1<<endl,exit(0);
  int j=n;
  for(int i=1;i<=n/2;i++)
  {
    if(sm==k)break;
    if(j-i+sm<=k)
    {
      sm+=j-i;swap(b[i],b[j]);
    }
    else
    {
      swap(b[i],b[i+k-sm]);
      sm=k;
    }
    j--;
  }
  cout<<sm<<endl;
  for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
  for(int i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;
  return 0;
}