/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/18/2020 23:03                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++17                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1368/problem/C
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
  int n;cin>>n;vector<pair<int,int> >v;
  for(int i=0;i<n*2-1;i++)v.push_back({0,i});
  for(int i=0;i<n*2-1;i+=2)v.push_back({-1,i});
  for(int i=0;i<n*2-1;i+=2)v.push_back({1,i});
   v.push_back({0,-1});v.push_back({0,n*2-1});
  v.push_back({1,-1});v.push_back({-1,n*2-1});
   //cout<<"gee"<<endl;
  if(n%2)
  {
    int dw=4,lf=4;
    int i=0;
    int d=-1;
    for(int j=1;j<=dw;j++)
      v.push_back({--d,i});
    int l=i;
    for(int j=1;j<=lf;j++)
      v.push_back({d,--l});
     for(int j=1;j<=2*dw+3;j++)
      v.push_back({++d,l});
     for(int j=1;j<=lf+2;j++)
      v.push_back({d,++l});
     for(int j=1;j<=dw;j++)
      v.push_back({--d,l});
    for(int i=2;i<n*2-3;i+=4)
    {
      v.push_back({-2,i});
      v.push_back({-2,i+1});
      v.push_back({-2,i+2});
    }
    for(int i=4;i<n*2-1;i+=4)
    {
      v.push_back({2,i});
      v.push_back({2,i+1});
      v.push_back({2,i+2});
    }
  }
  else
  {
    for(int i=0;i<n*2-3;i+=4)
    {
      v.push_back({-2,i});
      v.push_back({-2,i+1});
      v.push_back({-2,i+2});
    }
    for(int i=2;i<n*2-1;i+=4)
    {
      v.push_back({2,i});
      v.push_back({2,i+1});
      v.push_back({2,i+2});
    }
  }
  cout<<v.size()<<endl;
  for(auto x:v)
    cout<<x.first<<" "<<x.second<<endl;
    return 0;
}