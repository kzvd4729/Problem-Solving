/****************************************************************************************
*  @author: kzvd4729#                                        created: Oct/10/2020 15:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/549/problem/G
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
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;priority_queue<int>pq;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    pq.push(-(x+i-1));
  }
  int lz=0,ls=-1;vector<int>ans;
  while(pq.size())
  {
    int tp=abs(pq.top());pq.pop();
    tp-=lz;
     if(tp<ls)cout<<":(\n",exit(0);
    ls=tp,lz++;ans.push_back(tp);
  }
  for(auto x:ans)cout<<x<<" ";cout<<endl;
  return 0;
}