/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/08/2019 19:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 56000 KB                             
*  problem: https://codeforces.com/contest/514/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=6e5;
/**************** Hash ******************/
const long mod1=1000001011,mod2=1000009999;
const int b1=193,b2=307;
long pw1[N+2],pw2[N+2];
void Call(int n)
{
  pw1[0]=1;pw2[0]=1;
  for(int i=1;i<=n;i++)
  {
    pw1[i]=(pw1[i-1]*b1)%mod1;
    pw2[i]=(pw2[i-1]*b2)%mod2;
  }
}
struct Hash
{
  string s;vector<pair<long,long> >v;
  pair<long,long>make_hash(void)
  {
    long hs1=0,hs2=0;
    for(auto x:s)
    {
      hs1=(hs1*b1+x)%mod1;
      hs2=(hs2*b2+x)%mod2;
      v.push_back({hs1,hs2});
    }
    return {hs1,hs2};
  }
  pair<long,long>segment(int lt,int rt)
  {
    long x=v[rt].first,y=v[rt].second;
    if(!lt)return {x,y};
    x=(x-(v[lt-1].first*pw1[rt-lt+1])%mod1+mod1)%mod1;
    y=(y-(v[lt-1].second*pw2[rt-lt+1])%mod2+mod2)%mod2;
    return {x,y};
  }
}Hs[N+2];
/////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;Call(N);set<pair<int,int> >st;
  for(int i=1;i<=n;i++)
  {
    cin>>Hs[i].s;st.insert(Hs[i].make_hash());
  }
  while(m--)
  {
    Hash h;cin>>h.s;
    pair<long,long>pp=h.make_hash(),p,q;
    int sz=h.s.size()-1;int f=0;
    for(int i=0;i<=sz;i++)
    {
      int pw=sz-i;p=pp;
      if(h.s[i]=='a')
      {
        p.first=(p.first-(pw1[pw]*(long)'a')%mod1+mod1)%mod1;
        p.second=(p.second-(pw2[pw]*(long)'a')%mod2+mod2)%mod2;
         q=p;
        q.first=(q.first+(pw1[pw]*(long)'b')%mod1)%mod1;
        q.second=(q.second+(pw2[pw]*(long)'b')%mod2)%mod2;
        if(st.find(q)!=st.end())
        {
          cout<<"YES"<<"\n";f=1;break;
        }
        q=p;
        q.first=(q.first+(pw1[pw]*(long)'c')%mod1)%mod1;
        q.second=(q.second+(pw2[pw]*(long)'c')%mod2)%mod2;
        if(st.find(q)!=st.end())
        {
          cout<<"YES"<<"\n";f=1;break;
        }
      }
      else if(h.s[i]=='b')
      {
        p.first=(p.first-(pw1[pw]*(long)'b')%mod1+mod1)%mod1;
        p.second=(p.second-(pw2[pw]*(long)'b')%mod2+mod2)%mod2;
         q=p;
        q.first=(q.first+(pw1[pw]*(long)'a')%mod1)%mod1;
        q.second=(q.second+(pw2[pw]*(long)'a')%mod2)%mod2;
        if(st.find(q)!=st.end())
        {
          cout<<"YES"<<"\n";f=1;break;
        }
        q=p;
        q.first=(q.first+(pw1[pw]*(long)'c')%mod1)%mod1;
        q.second=(q.second+(pw2[pw]*(long)'c')%mod2)%mod2;
        if(st.find(q)!=st.end())
        {
          cout<<"YES"<<"\n";f=1;break;
        }
      }
      else if(h.s[i]=='c')
      {
        p.first=(p.first-(pw1[pw]*(long)'c')%mod1+mod1)%mod1;
        p.second=(p.second-(pw2[pw]*(long)'c')%mod2+mod2)%mod2;
         q=p;
        q.first=(q.first+(pw1[pw]*(long)'b')%mod1)%mod1;
        q.second=(q.second+(pw2[pw]*(long)'b')%mod2)%mod2;
        if(st.find(q)!=st.end())
        {
          cout<<"YES"<<"\n";f=1;break;
        }
        q=p;
        q.first=(q.first+(pw1[pw]*(long)'a')%mod1)%mod1;
        q.second=(q.second+(pw2[pw]*(long)'a')%mod2)%mod2;
        if(st.find(q)!=st.end())
        {
          cout<<"YES"<<"\n";f=1;break;
        }
      }
    }
    if(!f)cout<<"NO"<<"\n";
  }
  return 0;
}