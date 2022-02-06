/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/27/2020 14:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1216 ms                                         memory_used: 1700 KB                              
*  problem: https://codeforces.com/contest/1451/problem/D
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long d,k;cin>>d>>k;
    vector<long>v;
    for(long i=0;i*i<=d*d;i+=k)v.push_back(i*i);
     long mx=0;
    for(long i=0;i<v.size();i++)
    {
      long lo=0,hi=(int)v.size()-1,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(v[i]+v[md]>d*d)hi=md;
        else lo=md;
      }
      for(md=hi;md>=lo;md--)if(v[i]+v[md]<=d*d)break;
       mx=max(mx,i+md);
    }
    if(mx%2)cout<<"Ashish"<<endl;
    else cout<<"Utkarsh"<<endl;
  }
  return 0;
}