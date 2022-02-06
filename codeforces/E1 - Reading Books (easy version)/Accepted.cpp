/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/28/2020 21:13                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 156 ms                                          memory_used: 5300 KB                              
*  problem: https://codeforces.com/contest/1374/problem/E1
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
const int N=1e6,inf=2e9+1;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;vector<int>a,b,c;
  for(int i=1;i<=n;i++)
  {
    int x,y,z;cin>>x>>y>>z;
    if(y&&z)a.push_back(x);
    else if(y)b.push_back(x);
    else if(z)c.push_back(x);
  }
  sort(a.begin(),a.end()),sort(b.begin(),b.end()),sort(c.begin(),c.end());
  int ans=0,pa=0,pb=0,pc=0;
  for(int i=0;i<k;i++)
  {
    if(pa<a.size()&&pb<b.size()&&pc<c.size())
    {
      if(a[pa]<b[pb]+c[pc])ans+=a[pa++];
      else ans+=b[pb++]+c[pc++];
    }
    else if(pa<a.size())ans+=a[pa++];
    else if(pb<b.size()&&pc<c.size())ans+=b[pb++]+c[pc++];
    else cout<<-1<<endl,exit(0);
  }
  cout<<ans<<endl;
  return 0;
}