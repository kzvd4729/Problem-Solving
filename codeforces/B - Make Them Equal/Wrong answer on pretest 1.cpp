/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/27/2020 22:31                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/1416/problem/B
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
int a[N+2];
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int sm=0;
    for(int i=1;i<=n;i++)cin>>a[i],sm+=a[i];
     if(sm%n){cout<<-1<<'\n';continue;}
    vector<vector<int> >v;
     int tr=sm/n;
    for(int i=2;i<=n;i++)
    {
      int rq=(i-a[i]%i)%i;
      v.push_back({i,1,rq});
      a[i]+=rq;
       v.push_back({i,1,a[i]/i});
    }
    for(int i=2;i<=n;i++)v.push_back({1,i,tr});
    cout<<v.size()<<'\n';
    for(auto x:v)cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<'\n';
  }
  return 0;
}