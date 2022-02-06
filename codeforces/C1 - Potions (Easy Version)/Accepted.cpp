/****************************************************************************************
*  @author: * kzvd4729                                       created: May/28/2021 20:38                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1526/problem/C1
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
const int N=1e6,inf=1e9,mod=1000000007;
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;priority_queue<int>pq;
  long life=0;int cnt=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
     if(life+x>=0)
    {
      life+=x;cnt++;pq.push(-x);
    }
    else if((int)pq.size())
    {
      if((life+pq.top()+x>=0) && (pq.top()+x>0))
      {
        life+=pq.top();pq.pop();
        life+=x;pq.push(-x);
      }
    }
  }
  cout<<cnt<<endl;
      return 0;
}