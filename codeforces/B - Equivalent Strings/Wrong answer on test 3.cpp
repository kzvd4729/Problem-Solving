/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2020 15:30                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 7900 KB                              
*  problem: https://codeforces.com/contest/559/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
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
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cal(N);
  hsh a,b;cin>>a.s>>b.s;a.makeHash();b.makeHash();
  if(a.s==b.s)cout<<"YES\n",exit(0);
  int n=a.s.size();if(n!=b.s.size())cout<<"NO\n",exit(0);
  for(int i=0;i<n;i++)
  {
    pair<int,int>p1=a.segment(0,i);
    pair<int,int>p2=a.segment(i+1,n-1);
     pair<int,int>p3=b.segment(n-1-i,n-1);
    pair<int,int>p4=b.segment(0,n-i-2);
    //cout<<i<<" "<<
    if(p1==p3&&p2==p4)cout<<"YES\n",exit(0);
  }
  cout<<"NO\n",exit(0);
  return 0;
}