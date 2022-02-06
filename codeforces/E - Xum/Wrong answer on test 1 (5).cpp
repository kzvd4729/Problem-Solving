/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/13/2020 00:31                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1427/problem/E
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
const long N=1e6,inf=1e18;
vector<long>b;vector<vector<long> >ans;
bool isPossible(long x)
{
  for(auto y:b)
  {
    //ans.push_back({x,1,y});
    x=min(x,x^y);
  }
  return !((bool)x);
}
void insertX(long x)
{
  for(auto y:b)
  {
    //ans.push_back({x,1,y});
    x=min(x,(x^y));
  }
  if(!x)return;
  for(auto &y:b)
  {
    //ans.push_back({x,1,y});
    y=min(y,y^x);
  }
  b.push_back(x);sort(b.begin(),b.end());
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  vector<long>a;a.push_back(n);a.push_back(n+n);
  ans.push_back({n,0,n});ans.push_back({n,1,n});
  insertX(n);insertX(n+n);map<long,bool>mp;mp[n]=1,mp[n+n]=1;
   while(!isPossible(1))
  {
    int sz=a.size();
    long l=a[rng()%sz],r=a[rng()%sz];
    if(l<=inf&&r<=inf&&mp.count(l+r)==0&&isPossible(l+r)==0)
    {
      mp[l+r]=1;
      a.push_back(l+r);ans.push_back({l,0,r});insertX(l+r);
    }
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)
  {
    cout<<x[0];
    if(x[1])cout<<" ^ ";
    else cout<<" + ";
    cout<<x[2]<<'\n';
  }
  return 0;
}