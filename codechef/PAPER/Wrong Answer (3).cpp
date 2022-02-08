/****************************************************************************************
*  @author: kzvd4729                                         created: 25-01-2020 20:56:28                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/LTIME80A/problems/PAPER
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
long ds(int a,int b,int c,int d)
{
  return 1LL*(a-c)*(a-c)+1LL*(b-d)*(b-d);
}
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,w,h;cin>>n>>m>>w>>h;
    string s;cin>>s;
    bool up=0,dw=0,lt=0,rt=0;
    for(auto x:s)
    {
      if(x=='U')
      {
        if(up)dw=true;up=true;
      }
      if(x=='D')
      {
        if(dw)up=true;dw=true;
      }
      if(x=='L')
      {
        if(lt)rt=true;lt=true;
      }
      if(x=='R')
      {
        if(rt)lt=true;rt=true;
      }
    }
    long ans=4e18;//cout<<ans<<endl;
    for(int i=1;i<=m;i++)
    {
      int a,b;cin>>a>>b;
      for(int j=1;j<i;j++)ans=min(ans,ds(a,b,aa[j],bb[j]));
      if(up)ans=min(ans,4LL*(w-b)*(w-b));
      if(dw)ans=min(ans,4LL*b*b);
      if(lt)ans=min(ans,4LL*a*a);
      if(rt)ans=min(ans,4LL*(h-a)*(h-a));
      aa[i]=a,bb[i]=b;
    }
    double con=sqrt(ans*1.0);
    cout<<setprecision(9)<<fixed<<con<<"\n";
  }
  return 0;
}