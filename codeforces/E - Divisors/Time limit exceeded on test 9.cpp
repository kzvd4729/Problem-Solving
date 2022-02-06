/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/08/2020 19:46                        
*  solution_verdict: Time limit exceeded on test 9           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/448/problem/E
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
  long x,k;cin>>x>>k;
   vector<long>v;int sq=sqrt(x+1);
  for(int i=1;i<=sq;i++)
  {
    if(x%i==0)
    {
      v.push_back(i);
      if(x/i!=i)v.push_back(x/i);
    }
  }
  sort(v.begin(),v.end(),greater<long>());
  stack<pair<long,int> >st;st.push({x,0});
  int cnt=100000;
  while(st.size())
  {
    if(cnt==0)break;
    pair<long,int>p=st.top();st.pop();
    if(k==p.second||p.first==1)
    {
      cnt--;
      cout<<p.first<<" ";
    }
    else
    {
      for(auto x:v)
        if(p.first%x==0)st.push({x,p.second+1});
    }
  }
  cout<<endl;
  return 0;
}