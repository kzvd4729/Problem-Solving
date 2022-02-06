/****************************************************************************************
*  @author: kzvd4729                                         created: May/02/2019 23:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/461/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bit[N+2];
void upd(int x,int vl)
{
  for( ;x<=N;x+=x&-x)
    bit[x]+=vl;
}
int get(int x)
{
  int sm=0;
  for( ;x>0;x-=x&-x)
    sm+=bit[x];
  return sm;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q,lt,rt;cin>>n>>q;lt=1,rt=n;
  for(int i=1;i<=n;i++)aa[i]=1,upd(i,1);
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
          {
            aa[lt+x+ad]+=aa[i];
            upd(lt+x+ad,aa[i]);ad++;
          }
          lt+=x;n-=x;
        }
        else
        {
          int ad=0;
          for(int i=lt-x+1;i<=lt;i++)
          {
            aa[lt-x-ad]+=aa[i];
            upd(lt-x-ad,aa[i]);ad++;
          }
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
          {
            aa[rt-x-ad]+=aa[i];
            upd(rt-x-ad,aa[i]);ad++;
          }
          rt-=x;n-=x;
        }
        else
        {
          int ad=0;
          for(int i=rt+x-1;i>=rt;i--)
          {
            aa[rt+x+ad]+=aa[i];
            upd(rt+x+ad,aa[i]);ad++;
          }
          rt+=x;n-=x;
        }
        swap(lt,rt);
      }
    }
    else
    {
      int u,v,sm=0;cin>>u>>v;
      if(lt<=rt)cout<<get(lt+v-1)-get(lt+u-1)<<"\n";
      else cout<<get(lt-u)-get(lt-v)<<"\n";
    }
  }
  return 0;
}