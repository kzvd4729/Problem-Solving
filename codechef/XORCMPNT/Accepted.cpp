/****************************************************************************************
*  @author: kzvd4729                                         created: 12-10-2020 23:04:53                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.01 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/problems/XORCMPNT
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
vector<int>b;
bool isPossible(int x)
{
  for(auto y:b)x=min(x,x^y);
  return !x;
}
void insertX(int x)
{
  for(auto y:b)x=min(x,x^y);if(!x)return;
  for(auto &y:b)y=min(y,y^x);
  b.push_back(x);sort(b.begin(),b.end());
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>k>>n;b.clear();
    for(int i=0;i<n;i++)
    {
      int x;cin>>x;
      insertX(x);
    }
    int sz=k-b.size(),ans=1;assert(sz>=0);
    for(int i=1;i<=sz;i++)ans*=2;
    cout<<ans<<'\n';
  }
  return 0;
}