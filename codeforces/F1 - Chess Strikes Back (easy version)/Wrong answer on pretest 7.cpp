/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/19/2020 16:36                        
*  solution_verdict: Wrong answer on pretest 7               language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1379/problem/F1
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
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,q;cin>>n>>m>>q;
   bool h1=true,h2=true,v1=true,v2=true,l1=true,l2=true,r1=true,r2=true;
   while(q--)
  {
    int a,b;cin>>a>>b;
     if(a%2)h1=false;else h2=false;
     if(b%2)v1=false;else v2=false;
     if((a+b)%4)l1=false;else l2=false;
     if(abs(a-b)%4)r1=false;else r2=false;
     if(h1||h2||v1||v2)cout<<"YES\n";
    else cout<<"NO\n";
  }
   return 0;
}