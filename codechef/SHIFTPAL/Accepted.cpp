/****************************************************************************************
*  @author: kzvd4729                                         created: 26-05-2018 20:19:51                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.59 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/LTIME60A/problems/SHIFTPAL
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long l,t,ans,p,hs1,hs2,rs1,rs2;
long b1=31,b2=37;
long mod1=100030001,mod2=100767001;
string s;
long bigmod(long b,long p,long mod)
{
  long ret=1;
  while(p)
  {
    if(p&1)
      ret=(ret*b)%mod;
    b=(b*b)%mod;
    p/=2;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>s;
    l=s.size();
    p=1;
    hs1=0,hs2=0;
    for(int i=0;i<s.size();i++)
    {
      hs1=(hs1+(s[i]*1LL)*bigmod(b1,p,mod1))%mod1;
      hs2=(hs2+(s[i]*1LL)*bigmod(b2,p,mod2))%mod2;
      p++;
    }
    p=1;
    rs1=0,rs2=0;
    for(int i=s.size()-1;i>=0;i--)
    {
      rs1=(rs1+(s[i]*1LL)*bigmod(b1,p,mod1))%mod1;
      rs2=(rs2+(s[i]*1LL)*bigmod(b2,p,mod2))%mod2;
      p++;
    }
    ans=0;
    if(hs1==rs1&&hs2==rs2)ans=1;
    for(int i=0;i<s.size()-1;i++)
    {
      hs1=(hs1*bigmod(b1,mod1-2,mod1))%mod1;
      hs1=(hs1-s[i]*1LL+mod1)%mod1;
      hs1=(hs1+(s[i]*1LL)*bigmod(b1,l,mod1))%mod1;
      hs2=(hs2*bigmod(b2,mod2-2,mod2))%mod2;
      hs2=(hs2-s[i]*1LL+mod2)%mod2;
      hs2=(hs2+(s[i]*1LL)*bigmod(b2,l,mod2))%mod2;
      rs1=(rs1-((s[i]*1LL)*bigmod(b1,l,mod1))%mod1+mod1)%mod1;
      rs1=(rs1*b1)%mod1;
      rs1=(rs1+(s[i]*1LL)*bigmod(b1,1,mod1))%mod1;
      rs2=(rs2-((s[i]*1LL)*bigmod(b2,l,mod2))%mod2+mod2)%mod2;
      rs2=(rs2*b2)%mod2;
      rs2=(rs2+(s[i]*1LL)*bigmod(b2,1,mod2))%mod2;
      if(hs1==rs1&&hs2==rs2)ans++;
      //cout<<hs1<<" "<<hs2<<" "<<rs1<<" "<<rs2<<endl;
    }
    cout<<ans<<endl;
  }
  return 0;
}