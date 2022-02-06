/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/25/2020 22:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1468/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
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
int a[N+2],vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k,m;cin>>n>>k>>m;
    for(int i=1;i<=n;i++)vs[i]=0;
    for(int i=1;i<=m;i++)cin>>a[i],vs[a[i]]=1;
     if(n==m)
    {
      {cout<<"YES"<<endl;continue;}
    }
    if((n-m)%(k-1)){cout<<"NO"<<endl;continue;}
    int f=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
      if(!vs[i])cnt++;
      else 
      {
        if(cnt>=k/2&&(n-m)-cnt>=k/2)f=1;
      }
    }
    if(f)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}