/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/20/2019 18:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 20000 KB                             
*  problem: https://codeforces.com/contest/1200/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
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
    v.clear();s.clear();
  }
};
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cal(N);hsh h,m;
  int n;cin>>n;string ans;cin>>ans;
  for(int i=2;i<=n;i++)
  {
    cin>>h.s;h.makeHash();
    int sz=min((int)h.s.size(),(int)ans.size());
    m.s=ans.substr(ans.size()-sz,sz);
    m.makeHash();int id=0;
    for(int i=0;i<sz;i++)
    {
      if(h.segment(0,i)==m.segment(sz-1-i,sz-1))
        id=i+1;
    }
    while(id<h.s.size())ans.push_back(h.s[id++]);
    h.clear();m.clear();
  }
  cout<<ans<<endl;
  return 0;
}