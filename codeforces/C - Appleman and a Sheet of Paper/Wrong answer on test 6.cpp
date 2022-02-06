/****************************************************************************************
*  @author: kzvd4729                                         created: May/02/2019 21:58                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/461/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q,lt,rt;cin>>n>>q;lt=1,rt=n;
  for(int i=1;i<=n;i++)aa[i]=1;
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int x;cin>>x;
      if(x<=n/2)
      {
        int ad=0;
        for(int i=lt+x-1;i>=lt;i--)
          aa[lt+x+ad++]+=aa[i];
        lt+=x;n-=x;
        /*cout<<lt<<" --- "<<rt<<endl;
        for(int i=lt;i<=rt;i++)
          cout<<aa[i]<<" ";
        cout<<endl;*/
      }
      else
      {
        int ad=0;x=n-x;
        for(int i=rt-x+1;i<=rt;i++)
          aa[rt-x-ad++]+=aa[i];
        rt-=x;n-=x;
       /* cout<<lt<<" --- "<<rt<<endl;
        for(int i=lt;i<=rt;i++)
          cout<<aa[i]<<" ";
        cout<<endl;*/
      }
    }
    else
    {
      int u,v,sm=0;cin>>u>>v;
      for(int i=lt+u;i<lt+v;i++)
        sm+=aa[i];
      cout<<sm<<"\n";
    }
  }
  return 0;
}