/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/07/2021 22:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/1492/problem/D
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e5,inf=1e9,mod=1e9+7;
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int zero,one,k;cin>>zero>>one>>k;
   if(k==0)
  {
    cout<<"Yes"<<endl;
    for(int i=1;i<=one;i++)cout<<1;
    for(int i=1;i<=zero;i++)cout<<0;
    cout<<endl;
     for(int i=1;i<=one;i++)cout<<1;
    for(int i=1;i<=zero;i++)cout<<0;
    cout<<endl;
    exit(0);
  }
  if(one==1||zero==0)cout<<"No"<<endl,exit(0);
   string a,b;int n=zero+one;
  for(int i=0;i<n;i++)a.push_back('2');
  for(int i=0;i<n;i++)b.push_back('2');
   a[0]='1',b[0]='1';one--;
    a[n-1]='0';
  b[n-1]='1';
   if(n-1-k<1)cout<<"No"<<endl,exit(0);
   a[n-1-k]='1';
  b[n-1-k]='0';
   one--,zero--;
   for(int i=0;i<n;i++)
  {
    if(a[i]!='2')continue;
    if(one)a[i]='1',b[i]='1',one--;
    else a[i]='0',b[i]='0',zero--;
  }
  if(one!=0||zero!=0)assert(0);
  cout<<"Yes"<<endl;
  cout<<a<<endl;
  cout<<b<<endl;
    return 0;
}