/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: 100 points                              language: C++                                     
*  run_time: 177 ms                                          memory_used: 8544 KB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int mod=1000001011;
//and
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
        if(!inv)
        {
          a[i+j]=v;
          a[i+len+j]=(u+v>=mod?u+v-mod:u+v);
        }
        else
        {
          a[i+j]=(v-u<0?v-u+mod:v-u);
          a[i+len+j]=u;
        }
      }
    }
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
  int n;cin>>n;vector<int>a(N+1,0);
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;a[x]++;
  }
  int ans=1;
  multiply(a,n);
  for(auto x:a)
    ans+=(x>0);
  ans-=(a[0]>0);
  cout<<ans<<endl;
  return 0;
}