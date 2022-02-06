/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/11/2020 21:40                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 576 ms                                          memory_used: 135000 KB                            
*  problem: https://codeforces.com/contest/1366/problem/D
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e6,R=1e7;
int pr[R+2];
void seive()
{
  for(int i=4;i<=R;i+=2)pr[i]=2;
  int sq=sqrt(R+1);
  for(int i=3;i<=R;i+=2)
  {
    if(pr[i])continue;if(i>sq)continue;
    for(int j=i*i;j<=R;j+=2*i)pr[j]=i;
  }
}
int f[N+2],id;bool vs[R+2];
void fac(int n)
{
  id=0;
  while(true)
  {
    if(pr[n]==0)break;
    if(vs[pr[n]]==0)f[++id]=pr[n],vs[pr[n]]=1;
    n/=pr[n];
  }
  if(n>1)
  {
    if(vs[n]==0)f[++id]=n,vs[n]=1;
  }
  for(int i=1;i<=id;i++)vs[f[i]]=0;
}
int a[N+2],lt[R+2],rt[R+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;if(lt[x]!=0)continue;
    fac(x);int ff=0;
    for(int j=1;j<=id;j++)
    {
      for(int k=j+1;k<=id;k++)
      {
        int ad=f[j]+f[k];int g=0;
        for(int l=1;l<=id;l++)
          if(ad%f[l]==0){g=1;break;}
        if(g==0){lt[x]=f[j],rt[x]=f[k];ff=1;break;}
      }
      if(ff)break;
    }
    if(ff==0)lt[x]=-1,rt[x]=-1;a[i]=x;
  }
  for(int i=1;i<=n;i++)cout<<lt[a[i]]<<" ";cout<<endl;
  for(int i=1;i<=n;i++)cout<<rt[a[i]]<<" ";cout<<endl;
  return 0;
}