/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-03 20:35:53                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 105 ms                                          memory_used: 7976 KB                              
*  problem: https://atcoder.jp/contests/zone2021/tasks/zone2021_f
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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int vs[N+2],par[N+2];
 int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
  /*
basis for xor: S is set of some positive integer.
B is another set which is sbuset of S. we call B basis
of S if every element of S can be represented by xor value
of some subset of B and size of B is minimum possible.
*/
vector<int>b;//size of basis will always be <= log
//b is not necessarily subset of S.
bool isPossible(int x)
{
  for(auto y:b)x=min(x,x^y);
  return !x;
}
bool insertX(int x)//online
{
  for(auto y:b)x=min(x,x^y);if(!x)return false;
  for(auto &y:b)y=min(y,y^x);
  b.push_back(x);sort(b.begin(),b.end());
   return true;
}
//number of distinct possible value(0 included).
int maxSize()
{
  int p=1;
  for(int i=0;i<b.size();i++)p*=2;
  return p;
}
int kth(int k)
{
  int ret=0;k--;
  for(int i=0;i<b.size();i++)if((k>>i)&1)ret^=b[i];
  return ret;
}
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
   for(int i=0;i<m;i++)
  {
    int x;cin>>x;vs[x]=1;
  }
   vector<int>v;
  for(int i=0;i<n;i++)if(vs[i]==0 && insertX(i))v.push_back(i);
   //shuffle(v.begin(),v.end(),rng);
   //for(auto x:v)cout<<x<<" ";cout<<endl;
  for(int i=0;i<n;i++)par[i]=i;
   vector<pair<int,int> >ans;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<(int)v.size();j++)
    {
      int a=i,b=(i^v[j]);
       int p1=get(a),p2=get(b);
       if(p1==p2)continue;
      ans.push_back({a,b});par[p1]=p2;
    }
  }
   if((int)ans.size()!=n-1)cout<<-1<<'\n',exit(0);
   for(auto x:ans)cout<<x.first<<" "<<x.second<<'\n';
     return 0;
}