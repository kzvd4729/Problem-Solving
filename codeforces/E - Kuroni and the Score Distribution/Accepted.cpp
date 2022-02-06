/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/25/2020 18:17                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 11500 KB                             
*  problem: https://codeforces.com/contest/1305/problem/E
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
int a[N+2],cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int x=1000000000;
  for(int i=5000;i>=1;i--)
  {
    a[i]=x;x-=20000;
  }
  int n,m;cin>>n>>m;
  int mx=(n/2)*((n-1)/2);
  if(m>mx)cout<<-1<<endl,exit(0);
   int i;
  for(i=n;i>=1;i--)
  {
    if((i/2)*((i-1)/2)<=m){m-=(i/2)*((i-1)/2);break;}
  }
  for(int j=1;j<=i;j++)a[j]=j;
   if(m)
  {
    for(int j=1;j<=i;j++)
    {
      for(int k=j+1;k<=i;k++)
        cnt[j+k]++;
    }
    for(int j=i+1; ;j++)
    {
      if(cnt[j]==m){a[i+1]=j;break;}
    }
  }
  for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
  return 0;
}