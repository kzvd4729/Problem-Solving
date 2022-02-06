/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/19/2020 13:11                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/814/problem/D
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
const int N=1e3;
struct circle
{
  int a,b,c;
}cc[N+2];
bool isInside(int i,int j)
{
  long ds=1LL*(cc[i].a-cc[j].a)*(cc[i].a-cc[j].a);
  ds+=1LL*(cc[i].b-cc[j].b)*(cc[i].b-cc[j].b);
   long an=max(cc[i].c,cc[j].c);an*=an;
  return an>ds;
}
int vs[N+2],cl[N+2];vector<int>ad[N+2];
void dfs(int node,int c)
{
  cl[node]=c;
  for(auto x:ad[node])dfs(x,c^1);
}
const double pi=acos(-1.0);
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>cc[i].a>>cc[i].b>>cc[i].c;
   sort(cc+1,cc+n+1,[&](circle a,circle b){
    return a.c>b.c;
  });
  for(int i=n;i>=1;i--)
  {
    for(int j=i+1;j<=n;j++)
    {
      if(vs[j])continue;
      if(isInside(i,j))
      {
        vs[j]=1;ad[i].push_back(j);
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    if(vs[i])continue;
    for(auto x:ad[i])dfs(x,0);
  }
  double ans=0;
  for(int i=1;i<=n;i++)
  {
    double now=pi*cc[i].c*cc[i].c;
    if(cl[i])now*=-1;
    ans+=now;
  }
  cout<<setprecision(12)<<fixed<<ans<<endl;
  return 0;
}