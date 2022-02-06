/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/15/2019 19:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2214 ms                                         memory_used: 14800 KB                             
*  problem: https://codeforces.com/contest/710/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
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
set<pair<int,int> >st[N+2];
vector<int>un;int vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cal(N);int q;cin>>q;
  while(q--)
  {
    int ty;cin>>ty>>hs.s;int n=hs.s.size();
    if(ty==1)
    {
      st[n].insert(hs.makeHash());
      if(!vis[n])un.push_back(n),vis[n]=1;
    }
    else if(ty==2)st[n].erase(hs.makeHash());
    else
    {
      hs.makeHash();int ans=0;
      for(int i=0;i<hs.s.size();i++)
      {
        for(auto &x:un)
        {
          int l=i-x+1;if(l<0)continue;
          if(st[x].find(hs.segment(l,i))!=st[x].end())ans++;
        }
      }
      cout<<ans<<endl;
    }
    hs.clear();
  }
  return 0;
}