/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/30/2020 23:50                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1408/problem/F
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
  int n;cin>>n;
   vector<pair<int,int> >v;
  int p=1;
   for(int l=1;l<=20;l++)
  {
    for(int i=1;i<=n;i+=p+p)
    {
      if(i+p-1>n)break;
      for(int j=i;j<i+p;j++)
      {
        if(j<=n&&j+p<=n)v.push_back({j,j+p});
      }
    }
    p*=2;
  }
  cout<<v.size()<<'\n';
  for(auto x:v)cout<<x.first<<" "<<x.second<<'\n';
  return 0;
}