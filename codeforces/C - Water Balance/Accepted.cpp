/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/04/2020 15:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1949 ms                                         memory_used: 20800 KB                             
*  problem: https://codeforces.com/contest/1299/problem/C
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
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  deque<pair<int,double> >dq;
  dq.push_front({1,a[n]});
  for(int i=n-1;i>=1;i--)
  {
    int sz=1;double avg=a[i];
    while(dq.size())
    {
      pair<int,double>p=dq.front();
      if(p.second>avg)break;
       dq.pop_front();
      avg=(avg*sz+p.second*p.first)/((sz+p.first)*1.0);
      sz+=p.first;
    }
    dq.push_front({sz,avg});
  }
  cout<<setprecision(9)<<fixed;
  for(int i=0;i<dq.size();i++)
  {
    for(int j=1;j<=dq[i].first;j++)
    {
      cout<<dq[i].second<<" ";
    }
  }
  cout<<endl;
  return 0;
}