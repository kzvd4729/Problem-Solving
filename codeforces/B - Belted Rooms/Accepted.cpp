/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/03/2020 14:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 4900 KB                              
*  problem: https://codeforces.com/contest/1428/problem/B
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
int vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;string s;cin>>s;
    for(int i=0;i<n;i++)vs[i]=0;
    int f1=0,f2=0;
    for(int i=0;i<n;i++)
    {
      if(s[i]=='-')vs[i]=1,vs[(i+1)%n]=1;
      else if(s[i]=='>')f1=1;
      else f2=1;
    }
    if(f1+f2<=1)cout<<n<<endl;
    else
    {
      int cnt=0;
      for(int i=0;i<n;i++)cnt+=vs[i];
      cout<<cnt<<endl;
    }
  }
  return 0;
}