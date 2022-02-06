/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/17/2020 22:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 16800 KB                             
*  problem: https://codeforces.com/contest/1463/problem/D
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
int ok[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n+n;i++)ok[i]=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;ok[x]=1;
    }
    set<int>in,out;
    for(int i=1;i<=n+n;i++)
    {
      if(ok[i])in.insert(i);
      else out.insert(i);
    }
    int mn=0;
    for(int i=1;i<=n+n;i++)
    {
      if(in.find(i)!=in.end())
      {
        mn++;
        in.erase(i);
        auto it=out.rbegin();
        out.erase(*it);
      }
      else if(out.find(i)!=out.end())
      {
        out.erase(i);
        auto it=in.lower_bound(i);
        in.erase(*it);
      }
    }
     for(int i=1;i<=n+n;i++)
    {
      if(ok[i])in.insert(i);
      else out.insert(i);
    }
    int mx=0;
    for(int i=n+n;i>=1;i--)
    {
      if(in.find(i)!=in.end())
      {
        mx++;
        in.erase(i);
        auto it=out.begin();
        out.erase(*it);
      }
      else if(out.find(i)!=out.end())
      {
        out.erase(i);
        auto it=in.lower_bound(i);it--;
        in.erase(*it);
      }
    }
    cout<<max(0,n+1-mn-mx)<<endl;
  }
  return 0;
}