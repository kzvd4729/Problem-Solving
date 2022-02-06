/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/23/2019 14:15                        
*  solution_verdict: Wrong answer on test 33                 language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 47100 KB                             
*  problem: https://codeforces.com/contest/1257/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e6,inf=1e9;
 vector<int>r;
void bitReverse(int n)
{
  r.resize(n);for(int i=0;i<n;i++)r[i]=0;int p=0;while((1<<p)<n)p++;
  for(int i=0;i<n;i++){for(int j=0;j<p;j++)if(i&(1<<j))r[i]|=(1<<(p-j-1));}
}
int big(int b,int p,int mod)
{
  int ret=1;
  while(p){if(p%2)ret=(1LL*ret*b)%mod;b=(1LL*b*b)%mod;p/=2;}return ret;
}
void dft(vector<int>&a,bool inv,int mod,int g)
{
  int n=a.size();
  for(int i=0;i<n;i++)if(r[i]<i)swap(a[i],a[r[i]]);
  for(int ln=2;ln<=n;ln*=2)
  {
    int m=inv?big(g,mod-1-(mod-1)/ln,mod):big(g,(mod-1)/ln,mod);
    for(int i=0;i<n;i+=ln)
    {
      int r=1,u,v;
      for(int j=0;j<ln/2;j++)
      {
        u=a[i+j],v=(1LL*r*a[i+j+ln/2])%mod;a[i+j]=u+v<mod?u+v:u+v-mod;
        a[i+j+ln/2]=u-v>=0?u-v:u-v+mod;r=(1LL*r*m)%mod;
      }
    }
  }
  if(inv){int ni=big(n,mod-2,mod);for(auto &x:a)x=(1LL*x*ni)%mod;}
}
vector<int>multiply(vector<int>a,vector<int>b,int mod,int g)
{
  int sz=a.size()+b.size();int n=1;while(n<sz)n<<=1;bitReverse(n);
  a.resize(n);b.resize(n);dft(a,false,mod,g);dft(b,false,mod,g);
  for(int i=0;i<n;i++)a[i]=(1LL*a[i]*b[i])%mod;dft(a,true,mod,g);return a;
}
int exgcd(int a,int b,int &x,int &y,int mod)
{
  if(!b){x=1,y=0;return a;}
  int x1,y1;
  int g=exgcd(b,a%b,x1,y1,mod);
  x=y1,y=(x1-(1LL*(1LL*a*big(b,mod-2,mod))%mod*y1)%mod+mod)%mod;
  return g;
}
//remainder vector and modulo vector. modulo doesn't need to be co prime
int crt(vector<int>&a,vector<int>&m,int mod)
{
  int ans=a[0],lcm=m[0];
  for(int i=1;i<a.size();i++)
  {
    int x,y;int g=exgcd(lcm,m[i],x,y,mod);
    if((a[i]-ans)%g!=0)assert(0);//no solution
    int md=(1LL*(1LL*lcm*big(g,mod-2,mod))%mod*m[i])%mod;
     long tmp=(a[i]-ans+mod)%mod;
    tmp=(tmp*big(g,mod-2,mod))%mod;
    tmp=(tmp*x)%mod;
     tmp%=((1LL*m[i]*big(g,mod-2,mod))%mod);
    tmp=(1LL*tmp*lcm)%md;ans=(ans+tmp)%mod;
     lcm=md;ans=(ans+lcm)%lcm;
  }
  return ans;
}
vector<int>multiply(vector<int>a,vector<int>b)
{
 vector<int>c1=multiply(a,b,786433,10);
  vector<int>c2=multiply(a,b,1004535809,3);
  vector<int>c3=multiply(a,b,469762049,3);
  vector<int>ret,aa,mm;int mod=998244353;
  for(int i=0;i<c1.size();i++)
  {
    aa.clear(),mm.clear();
    aa={c1[i],c2[i],c3[i]};mm={786433,1004535809,469762049};
    ret.push_back(crt(aa,mm,mod));
  }
  return ret;
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
     v[a.second]=multiply(v[a.second],v[b.second]);
    st.insert({v[a.second].size(),a.second});
  }
  pair<int,int>a=*st.begin();
  cout<<v[a.second][n/2]<<endl;
  return 0;
}