/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/12/2020 16:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 47000 KB                             
*  problem: https://codeforces.com/contest/1334/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long bg[N+2],ed[N+2],st[N+2],sq[N+2],gn[N+N+2],n;
void gen(long id)
{
  if(id==n)
  {
    gn[1]=1;return ;
  }
  long j=0;
  for(long i=id+1;i<=n;i++)
  {
    gn[++j]=id;gn[++j]=i;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long l,r;cin>>n>>l>>r;
     for(int i=1;i<n;i++)
    {
      bg[i]=ed[i-1]+1;
      ed[i]=ed[i-1]+(n-i)*2;
    }
    bg[n]=ed[n-1]+1;ed[n]=bg[n];
     /*for(long i=1;i<=n;i++)
    {
      gen(i);long id=0;
      for(long j=bg[i];j<=ed[i];j++)
        cout<<gn[++id]<<" ";
      cout<<endl;
    }*/
     for(long i=1;i<=n;i++)
    {
      if(l>ed[i]||r<bg[i])continue;
      gen(i);
      for(long j=bg[i];j<=ed[i];j++)
        if(j>=l&&j<=r)cout<<gn[j-bg[i]+1]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}