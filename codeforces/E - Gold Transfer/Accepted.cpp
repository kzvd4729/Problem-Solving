/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/04/2021 22:27                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 2199 ms                                         memory_used: 93900 KB                             
*  problem: https://codeforces.com/contest/1535/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int aa[N+2],cc[N+2],sp[N+2][20+2];
 void upd(int i,int p)
{
  sp[i][0]=p;
  for(int j=1;j<=20;j++)
  {
    sp[i][j]=sp[i][j-1];
    if(sp[i][j-1]!=-1)
      sp[i][j]=sp[sp[i][j-1]][j-1];
  }
}
int findFirst(int nd)
{
  int d=0;
  for(int i=20;i>=0;i--)
  {
    if(sp[nd][i]==-1)continue;
    if(aa[sp[nd][i]])nd=sp[nd][i],d+=(1<<i);
  }
  return d;
}
int raise(int nd,int d)
{
  for(int i=20;i>=0;i--)
  {
    if((1<<i)<=d)nd=sp[nd][i],d-=(1<<i);
  }
  return nd;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  memset(sp,-1,sizeof sp);
   int q,a,c;cin>>q>>aa[0]>>cc[0];
   upd(0,-1);
   for(int i=1;i<=q;i++)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int p;cin>>p>>aa[i]>>cc[i];
      upd(i,p);
    }
    else
    {
      int v,w;cin>>v>>w;int ww=w;
      int d=findFirst(v);
       long cs=0;
      for(int j=d;j>=0;j--)
      {
        int nd=raise(v,j);
        if(aa[nd]>=w)
        {
          cs+=1LL*cc[nd]*w;
          aa[nd]-=w;w=0;break;
        }
        else
        {
          cs+=1LL*cc[nd]*aa[nd];
          w-=aa[nd];aa[nd]=0;
        }
      }
      //for(int j=0;j<=i;j++)cout<<aa[j]<<" ";cout<<endl;
      cout<<ww-w<<" "<<cs<<endl;
    }
  }
    return 0;
}