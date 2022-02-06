/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/18/2020 17:57                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 327 ms                                          memory_used: 24700 KB                             
*  problem: https://codeforces.com/contest/1061/problem/F
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int>bf;
void ck(int n,int a,int c)
{
  bf.clear();
  for(int b=1;b<=n;b++)
  {
    if(a==b||c==b)continue;
    cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
    string s;cin>>s;
    if(s[0]=='Y')bf.push_back(b);
  }
}
int ck(int r)
{
  int cnt=0;
  for(int i=0;i<bf.size();i++)
  {
    for(int j=i+1;j<bf.size();j++)
    {
      if(bf[i]==r||bf[j]==r)continue;
      cout<<"? "<<bf[i]<<" "<<r<<" "<<bf[j]<<endl;
      string s;cin>>s;
      if(s[0]=='Y')cnt++;
    }
  }
  return cnt;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  vector<pair<int,int> >v;
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)v.push_back({i,j});
  }
  shuffle(v.begin(),v.end(),rng);
   int nn=n,dp=0,p=1;
  while(nn)
  {
    assert(nn>=0);
    nn-=p;dp++;p*=k;
  }
  for(int i=0;i<v.size();i++)
  {
    ck(n,v[i].first,v[i].second);
    if(bf.size()==(dp-1)*2-1)break;
  }
  for(auto x:bf)
  {
    if(ck(x)==(dp-2)*(dp-2))
    {
      cout<<"! "<<x<<endl;exit(0);
    }
  }
  assert(0);
  return 0;
}