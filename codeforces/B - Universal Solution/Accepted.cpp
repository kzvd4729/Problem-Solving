/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/12/2020 21:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1380/problem/B
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
void print(int n,char c)
{
  for(int i=1;i<=n;i++)cout<<c;
    cout<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;int a=0,b=0,c=0;
    for(auto x:s)
    {
      if(x=='R')a++;
      else if(x=='P')b++;
      else c++;
    }
    if(a>=b&&a>=c)print(s.size(),'P');
    else if(b>=a&&b>=c)print(s.size(),'S');
    else print(s.size(),'R');
  }
  return 0;
}