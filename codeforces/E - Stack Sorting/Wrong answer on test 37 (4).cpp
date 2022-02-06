/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/21/2020 21:14                        
*  solution_verdict: Wrong answer on test 37                 language: GNU C++17                               
*  run_time: 109 ms                                          memory_used: 7400 KB                              
*  problem: https://codeforces.com/contest/911/problem/E
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
const int N=2e5;
int a[N+2];
void no(){cout<<-1<<endl,exit(0);}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=k;i++)cin>>a[i];
   stack<int>sk;sk.push(n+2);int tr=1;
  for(int i=1;i<=k;i++)
  {
    if(a[i]>sk.top())no();sk.push(a[i]);
    while(sk.size())
    {
      if(sk.top()==tr)sk.pop(),tr++;
      else break;
    }
  }
  set<int>st;
  for(int i=1;i<=n;i++)st.insert(i);
  for(int i=1;i<=k;i++)st.erase(a[i]);
   while(st.size())
  {
    auto it=st.lower_bound(sk.top());
    if(it==st.begin())assert(0);
    it--;
     sk.push(*it);st.erase(*it);a[++k]=*it;
    while(sk.size())
    {
      if(sk.top()==tr)sk.pop(),tr++;
      else break;
    }
  }
  if(sk.size()>1)assert(0);
  for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
  return 0;
}