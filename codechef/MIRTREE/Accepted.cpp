/****************************************************************************************
*  @author: kzvd4729                                         created: 07-04-2019 21:33:46                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/ALKH2019/problems/MIRTREE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=1000000007;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;long nd=1;
  for(int i=1;i<=n;i++)
    nd=(nd*2LL)%mod;
  long top=1,left=n+1,right=n+1,bottom=nd;
  nd=(nd+nd-1+mod)%mod;long ed=(nd-1+mod)%mod;
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int x;cin>>x;
      if(x==1)
      {
        nd=(nd+nd)%mod;
        ed=(ed+ed+right)%mod;
        top=(top+top)%mod;
        bottom=(bottom+bottom)%mod;
      }
      else if(x==2)
      {
        nd=(nd+nd)%mod;
        ed=(ed+ed+left)%mod;
        top=(top+top)%mod;
        bottom=(bottom+bottom)%mod;
      }
      else if(x==3)
      {
        nd=(nd+nd)%mod;
        ed=(ed+ed+top)%mod;
        left=(left+left)%mod;
        right=(right+right)%mod;
        top=bottom;
      }
      else
      {
        nd=(nd+nd)%mod;
        ed=(ed+ed+bottom)%mod;
        left=(left+left)%mod;
        right=(right+right)%mod;
        bottom=top;
      }
    }
    else
    {
      cout<<ed<<"\n";
    }
  }
  return 0;
}