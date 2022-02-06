/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/04/2020 21:42                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 11600 KB                             
*  problem: https://codeforces.com/contest/1375/problem/D
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
int a[N+2],v[N+2];
int mex(int n)
{
  for(int i=0;i<=n;i++)v[i]=0;
   for(int i=0;i<n;i++)v[a[i]]=1;
  for(int i=0;i<=n;i++)if(v[i]==0)return i;
  assert(0);
}
bool idOK(int n)
{
  for(int i=1;i<n;i++)
    if(a[i]<a[i-1])return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
     vector<int>ans;
    while(true)
    {
      if(idOK(n))break;int x=mex(n);
      if(x<n)
      {
        ans.push_back(x);
        a[x]=x;continue;
      }
      for(int i=0;i<n;i++)
      {
        if(a[i]!=i)
        {
          ans.push_back(i),a[i]=x;
          break;
        }
      }
    }
    assert(ans.size()<=2*n);
    cout<<ans.size()<<"\n";
    for(auto x:ans)cout<<x+1<<" ";cout<<"\n";
  }
  return 0;
}