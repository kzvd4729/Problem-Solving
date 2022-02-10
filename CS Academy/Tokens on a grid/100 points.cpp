/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: 100 points                              language: C++                                     
*  run_time: 1177 ms                                         memory_used: 1060 KB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int mod=1e9+7;
//or
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
          a[i+j]=(u+v>=mod?u+v-mod:u+v);
          a[i+len+j]=u;
        }
        else
        {
          a[i+j]=v;
          a[i+len+j]=(u-v<0?u-v+mod:u-v);
        }
      }
    }
  }
}
string s[20];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=0;i<n;i++)
    cin>>s[i];
  vector<int>ans((1<<n),1);
  for(int j=0;j<m;j++)
  {
    vector<int>msk(30,0);
    for(int i=0;i<n;i++)
    {
      if(s[i][j]=='.')continue;
      msk[s[i][j]-'a']|=(1<<i);
    }
    vector<int>a((1<<n),0);a[0]=1;
    for(int i=0;i<26;i++)
    {
      for(int sub=msk[i];sub>0;sub=(sub-1)&msk[i])
        a[sub]=1;
    }
    fwht(a,0);
    for(int i=0;i<(1<<n);i++)
      ans[i]=(1LL*ans[i]*a[i])%mod;
  }
  fwht(ans,1);vector<int>pr(20,0);
  for(int i=0;i<(1<<n);i++)
    pr[__builtin_popcount(i)]=(pr[__builtin_popcount(i)]+ans[i])%mod;
  for(int i=0;i<=n;i++)
    cout<<pr[n-i]<<" ";
  cout<<endl;
  return 0;
}