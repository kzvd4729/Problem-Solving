/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/20/2020 21:51                        
*  solution_verdict: Wrong answer on pretest 10              language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/1370/problem/E
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string a,b;cin>>a>>b;
  if(a==b)cout<<0<<endl,exit(0);
  int c=0,d=0;
  for(int i=0;i<n;i++)c+=(a[i]=='0');
  for(int i=0;i<n;i++)d+=(b[i]=='0');
  if(c!=d)cout<<-1<<endl,exit(0);
    string x;
  for(int i=0;i<n;i++)
    if(a[i]!=b[i])x.push_back(a[i]);
  //cout<<x<<endl;
  x+=x;
   int cnt=1,ans=1;
  for(int i=1;i<x.size();i++)
  {
    if(x[i]==x[i-1])cnt++;
    else cnt=1;
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
  return 0;
}