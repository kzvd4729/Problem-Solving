/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/23/2019 16:12                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/632/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int mod=786433,r=10;//generator//primitive root
int big(int b,int p)
{
  int ret=1;
  while(p)
  {
    if(p%2)ret=(1LL*ret*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return ret;
}
void fft(vector<int>&a,bool inv)
{
  int n=a.size();
  for(int i=1,j=0;i<n;i++)
  {
    int bit=n>>1;
    for( ;bit&j;bit>>=1)
      j^=bit;
    j^=bit;
    if(i<j)swap(a[i],a[j]);
  }
  for(int len=2;len<=n;len<<=1)
  {
    int wlen=inv?big(r,mod-1-(mod-1)/len):big(r,(mod-1)/len);
    for(int i=0;i<n;i+=len)
    {
      int w=1;
      for(int j=0;j<len/2;j++)
      {
        int u=a[i+j],v=(1LL*a[i+j+len/2]*w)%mod;
        a[i+j]=u+v<mod?u+v:u+v-mod;
        a[i+j+len/2]=u-v>=0?u-v:u-v+mod;
        w=(1LL*w*wlen)%mod;
      }
    }
  }
  if(inv)
  {
    int ni=big(n,mod-2);
    for(auto &x:a)x=(1LL*x*ni)%mod;
  }
}
vector<int>multiply(vector<int>&a,int k)
{
  //a^0+a^1+a^2+a^3+... format
  int sz=a.size()+a.size();
  int n=1;while(n<sz)n<<=1;
  vector<int>fa(a.begin(),a.end());
  fa.resize(n);fft(fa,false);
  for(int i=0;i<n;i++)fa[i]=big(fa[i],k);
  fft(fa,true);return fa;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;vector<int>a(1001,0);
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;a[x]=1;
  }
  a=multiply(a,k);
  for(int i=1;i<a.size();i++)
    if(a[i])cout<<i<<" ";
  cout<<endl;
  return 0;
}