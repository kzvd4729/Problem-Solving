/****************************************************************************************
*  @author: kzvd4729#                                        created: May/29/2020 20:34                        
*  solution_verdict: Wrong answer on test 16                 language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 5200 KB                              
*  problem: https://codeforces.com/contest/439/problem/C
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
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k,p;cin>>n>>k>>p;vector<int>a,b;p=k-p;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(x%2==0)a.push_back(x);
    else b.push_back(x);
  }
  if(b.size()<p)cout<<"NO"<<endl,exit(0);
  if((b.size()-p)%2)cout<<"NO"<<endl,exit(0);
  if(k-p>a.size()+(b.size()-p)/2)cout<<"NO"<<endl,exit(0);
   cout<<"YES"<<endl;
  for(int i=1;i<p;i++)
  {
    cout<<1<<" "<<b.back()<<endl;
    b.pop_back();
  }
  if(p==k)
  {
    cout<<a.size()+b.size()<<" ";
    for(auto x:a)cout<<x<<" ";
    for(auto x:b)cout<<x<<" ";
    cout<<endl,exit(0);
  }
  cout<<1<<" "<<b.back()<<endl;
  b.pop_back();
  for(int i=1;i<k-p;i++)
  {
    if(a.size())
    {
      cout<<1<<" "<<a.back()<<endl;
      a.pop_back();
    }
    else
    {
      cout<<2<<" "<<b.back()<<" ";
      b.pop_back();
      cout<<b.back()<<endl;b.pop_back();
    }
  }
  cout<<a.size()+b.size()<<" ";
  for(auto x:a)cout<<x<<" ";
  for(auto x:b)cout<<x<<" ";
  cout<<endl,exit(0);
  return 0;
}