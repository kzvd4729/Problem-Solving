/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/25/2020 19:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1468/problem/N
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
int a[N+2],c[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    for(int i=1;i<=3;i++)cin>>c[i];
    for(int i=1;i<=5;i++)cin>>a[i];
     int f=1;
    for(int i=1;i<=3;i++)
    {
      c[i]-=a[i];
      if(c[i]<0)f=0;
    }
    if(f==0){cout<<"NO"<<endl;continue;}
    a[4]-=c[1];a[5]-=c[2];
    if(a[4]<0)a[4]=0;if(a[5]<0)a[5]=0;
     if(a[4]+a[5]<=c[3])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}