/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-08-27 18:46:54                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 826                                        memory_used (MB): 46                              
*  problem: https://vjudge.net/problem/HDU-2846
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
#include<unordered_set>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e6;

const int mod1=1000001011,mod2=1000009999;
const int b1=193,b2=307;
int pw1[N+2],pw2[N+2];
void cal(int n)
{
  pw1[0]=1;pw2[0]=1;
  for(int i=1;i<=n;i++)
  {
    pw1[i]=(1LL*pw1[i-1]*b1)%mod1;
    pw2[i]=(1LL*pw2[i-1]*b2)%mod2;
  }
}
struct hsh
{
  string s;vector<pair<int,int> >v;
  pair<int,int>makeHash(void)
  {
    int hs1=0,hs2=0;
    for(auto x:s)
    {
      hs1=(1LL*hs1*b1+x)%mod1;
      hs2=(1LL*hs2*b2+x)%mod2;
      v.push_back({hs1,hs2});
    }
    return {hs1,hs2};
  }
  pair<int,int>segment(int lt,int rt)
  {
    int x=v[rt].first,y=v[rt].second;
    if(!lt)return {x,y};
    x=x-(1LL*v[lt-1].first*pw1[rt-lt+1])%mod1;
    y=y-(1LL*v[lt-1].second*pw2[rt-lt+1])%mod2;
    if(x<0)x+=mod1;if(y<0)y+=mod2;
    return {x,y};
  }
  void clear(void)
  {
    v.clear();
  }
}hs;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cal(N);
  int n;cin>>n;map<pair<int,int>,int>mp[20+2];
  for(int i=1;i<=n;i++)
  {
    cin>>hs.s;hs.makeHash();
    for(int i=1;i<=hs.s.size();i++)
    {
      set<pair<int,int> >tmp;
      for(int j=0; ;j++)
      {
        if(j+i>hs.s.size())break;
        tmp.insert(hs.segment(j,j+i-1));
      }
      for(auto x:tmp)mp[i][x]++;
    }
    hs.clear();
  }
  int q;cin>>q;
  while(q--)
  {
    cin>>hs.s;pair<int,int>p=hs.makeHash();
    cout<<mp[hs.s.size()][p]<<'\n';
  }
  return 0;
}