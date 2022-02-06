/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/30/2020 21:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 343 ms                                          memory_used: 64900 KB                             
*  problem: https://codeforces.com/contest/1408/problem/D
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
int a[N+2],b[N+2],c[N+2],d[N+2];
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
  for(int i=1;i<=m;i++)cin>>c[i]>>d[i];
   vector<pair<int,int> >v;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      v.push_back({max(0,c[j]+1-a[i]),max(0,d[j]+1-b[i])});
  }
  sort(v.begin(),v.end());
  vector<int>mx(v.size()+2);
  mx[(int)v.size()]=0;
  for(int i=v.size()-1;i>=0;i--)
    mx[i]=max(mx[i+1],v[i].second);
  int ans=mx[0];
  for(int i=0;i<v.size();i++)
    ans=min(ans,v[i].first+mx[i+1]);
  cout<<ans<<endl;
  return 0;
}