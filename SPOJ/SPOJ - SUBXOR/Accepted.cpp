/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-15 23:29:50                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 920                                        memory_used (MB): 113.7                           
*  problem: https://vjudge.net/problem/SPOJ-SUBXOR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9;
int aa[N+2],nw,tr[20*N+2][20];
void add(int x)
{
  int now=0;
  for(int i=18;i>=0;i--)
  {
    bool z=(x&(1<<i));
    if(!tr[now][z])tr[now][z]=++nw;
    now=tr[now][z];tr[now][19]++;
  }
}
int qry(int x,int k)
{
  int ret=0,now=0;
  for(int i=18;i>=0;i--)
  {
    bool z=(x&(1<<i));
    if(k&(1<<i))
    {
      ret+=tr[tr[now][z]][19];now=tr[now][z^1];
    }
    else now=tr[now][z];
    
    if(now==0)return ret;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;add(0);
    int xxr=0,nw=0;long ans=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;xxr^=x;
      ans+=qry(xxr,k);add(xxr);
      //cout<<ans<<endl;
    }
    cout<<ans<<"\n";

    for(int i=0;i<=nw;i++)memset(tr[i],0,sizeof(tr[i]));
  }
  return 0;
}