/****************************************************************************************
*  @author: kzvd4729#                                        created: Apr/18/2021 22:11                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1406/problem/A
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
const int N=1e6,inf=1e9,mod=1e9+7;
 int fr[100+2];
 int mex(vector<int>a)
{
  sort(a.begin(),a.end());
   for(int i=0; ;i++)
    if(binary_search(a.begin(),a.end(),i)==0)return i;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    memset(fr,0,sizeof fr);
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      fr[x]++;
    }
     vector<int>a,b;
    for(int i=0;i<=100;i++)
    {
      if(fr[i]==0)continue;
      a.push_back(i);
       if(fr[i]>1)b.push_back(i);
    }
    cout<<mex(a)+mex(b)<<endl;
  }
  return 0;
}