/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/26/2019 18:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2932 ms                                         memory_used: 91000 KB                             
*  problem: https://codeforces.com/contest/1257/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e6,inf=1e9;
vector<int>r;
void bitReverse(int n)//n is power of 2
{
  r.resize(n);for(int i=0;i<n;i++)r[i]=0;
  int p=0;while((1<<p)<n)p++;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<p;j++)
      if(i&(1<<j))r[i]|=(1<<(p-j-1));
  }
}
int big(int b,int p,int mod)
{
  int ret=1;
  while(p)
  {
    if(p%2)ret=(1LL*ret*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return ret;
}
void dft(vector<int>&a,bool inv,int g,int mod)
{
  int n=a.size();
  for(int i=0;i<n;i++)
    if(r[i]<i)swap(a[i],a[r[i]]);
  for(int ln=2;ln<=n;ln*=2)
  {
    int m=inv?big(g,mod-1-(mod-1)/ln,mod):big(g,(mod-1)/ln,mod);
    for(int i=0;i<n;i+=ln)
    {
      int r=1,u,v;
      for(int j=0;j<ln/2;j++)
      {
        u=a[i+j],v=(1LL*r*a[i+j+ln/2])%mod;
        a[i+j]=u+v<mod?u+v:u+v-mod;
        a[i+j+ln/2]=u-v>=0?u-v:u-v+mod;
        r=(1LL*r*m)%mod;
      }
    }
  }
  if(inv)
  {
    int ni=big(n,mod-2,mod);
    for(auto &x:a)x=(1LL*x*ni)%mod;
  }
}
//a^0+a^1+a^2+a^3+... format
vector<int>multiply(vector<int>a,vector<int>b,int g,int mod)
{
  int sz=a.size()+b.size();
  int n=1;while(n<sz)n<<=1;bitReverse(n);
  a.resize(n);b.resize(n);
  dft(a,false,g,mod);dft(b,false,g,mod);
  for(int i=0;i<n;i++)a[i]=(1LL*a[i]*b[i])%mod;
  dft(a,true,g,mod);return a;
}
int cnt[N+2];
vector<int>v[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int p;cin>>p;cnt[p]++;
  }
  int id=0;set<pair<int,int> >st;
  for(int i=1;i<=N;i++)
  {
    if(!cnt[i])continue;
    v[++id].assign(cnt[i]+1,1);
    st.insert({cnt[i]+1,id});
  }
  while(st.size()>1)
  {
    pair<int,int>a=*st.begin();st.erase(a);
    pair<int,int>b=*st.begin();st.erase(b);
     v[a.second]=multiply(v[a.second],v[b.second],3,998244353);
    st.insert({v[a.second].size(),a.second});
  }
  pair<int,int>a=*st.begin();
  cout<<v[a.second][n/2]<<endl;
  return 0;
}