/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: 100 points                              language: C++                                     
*  run_time: 23 ms                                           memory_used: 900 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int mod=30011;
//xor
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
void fwht(vector<int>&a,bool inv)
{
  int n=a.size();//sizeof(a) is power of two;
  for(int len=1;2*len<=n;len<<=1)
  {
    for(int i=0;i<n;i+=2*len)
    {
      for(int j=0;j<len;j++)
      {
        int u=a[i+j],v=a[i+j+len];
        a[i+j]=(u+v>=mod?u+v-mod:u+v);
        a[i+j+len]=(u-v<0?u-v+mod:u-v);
      }
    }
  }
  if(inv)
  {
    int inv=big(n,mod-2);
    for(int i=0;i<n;i++)
      a[i]=(1LL*a[i]*inv)%mod;
  }
}
void multiply(vector<int>&a,int p)
{
  int sz=a.size(),n=1;
  while(n<sz)n<<=1;
  a.resize(n);fwht(a,0);
  for(int i=0;i<n;i++)
    a[i]=big(a[i],p);
  fwht(a,1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;vector<int>a(k+1,1);
  multiply(a,n);
  int ans=0;
  for(int i=1;i<a.size();i++)
    ans=(ans+a[i]>=mod?ans+a[i]-mod:ans+a[i]);
  cout<<ans<<endl;
  return 0;
}