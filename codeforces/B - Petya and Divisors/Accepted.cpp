/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/07/2020 14:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 10100 KB                             
*  problem: https://codeforces.com/contest/111/problem/B
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
const int N=1e5;
vector<int>dv[N+2];
void dvv()
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)dv[j].push_back(i);
  }
}
int ls[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  dvv();int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x,y;cin>>x>>y;int cnt=0;
    for(auto d:dv[x])
    {
      if(ls[d]<i-y)cnt++;
      ls[d]=i;
    }
    cout<<cnt<<" ";
  }
  cout<<endl;
  return 0;
}