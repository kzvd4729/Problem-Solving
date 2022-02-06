/****************************************************************************************
*  @author: kzvd4729                                         created: May/02/2019 23:10                        
*  solution_verdict: Time limit exceeded on test 19          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 3900 KB                              
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
        if(lt<=rt)
        {
          int ad=0;
          for(int i=lt+x-1;i>=lt;i--)
            aa[lt+x+ad++]+=aa[i];
          lt+=x;n-=x;
        }
        else
        {
          int ad=0;
          for(int i=lt-x+1;i<=lt;i++)
            aa[lt-x-ad++]+=aa[i];
          lt-=x;n-=x;
        }
      }
      else
      {
        x=n-x;
        if(lt<=rt)
        {
          int ad=0;
          for(int i=rt-x+1;i<=rt;i++)
            aa[rt-x-ad++]+=aa[i];
          rt-=x;n-=x;
        }
        else
        {
          int ad=0;
          for(int i=rt+x-1;i>=rt;i--)
            aa[rt+x+ad++]+=aa[i];
          rt+=x;n-=x;
        }
        swap(lt,rt);
      }
    }
    else
    {
      int u,v,sm=0;cin>>u>>v;
      if(lt<=rt)
      {
        for(int i=lt+u;i<lt+v;i++)
          sm+=aa[i];
      }
      else
      {
        for(int i=lt-u;i>lt-v;i--)
          sm+=aa[i];
      }
      cout<<sm<<"\n";
    }
    /*cout<<lt<<" "<<rt<<endl;
    for(int i=lt;i<=rt;i++)
      cout<<aa[i]<<" ";
    cout<<endl;
    if(lt>rt)assert(0);*/
  }
  return 0;
}