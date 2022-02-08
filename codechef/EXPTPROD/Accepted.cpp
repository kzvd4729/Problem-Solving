/****************************************************************************************
*  @author: kzvd4729                                         created: 24-04-2020 13:46:47                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 1.02 sec                                        memory_used: 15M                                  
*  problem: https://www.codechef.com/problems/EXPTPROD
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int n;
vector<int>multiply(vector<int>&a,vector<int>&b)
{
  vector<int>c(n);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
      c[(i*j)%n]=(c[(i*j)%n]+1LL*a[i]*b[j])%mod;
  }
  return c;
}
vector<int>expo(vector<int>&b,int p)
{
  vector<int>ret(n,0);ret[1]=1;
  while(p)
  {
    if(p&1)ret=multiply(ret,b);
    b=multiply(b,b);p/=2;
  }
  return ret;
}
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int k;cin>>n>>k;vector<int>a(n);
    for(int i=0;i<n;i++)
    {
      int x;cin>>x;a[x]++;
    }
    a=expo(a,k);int up=0;
    //for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
    for(int i=0;i<n;i++)up=(up+1LL*a[i]*i)%mod;
    int dw=big(n,k);
    cout<<(1LL*up*big(dw,mod-2))%mod<<"\n";
  }
  return 0;
}