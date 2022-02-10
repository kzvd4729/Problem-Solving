/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-29 22:43:43                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 100                                        memory_used (MB): 18.4                            
*  problem: https://vjudge.net/problem/SPOJ-ANDROUND
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=6e4;
long seg[4*N+2],arr[N+2],t,n,k,id,lft,rgt;
void build(long node,long lo,long hi)
{
  if(lo==hi)
  {
    seg[node]=arr[lo];
    return ;
  }
  long md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);
  seg[node]=seg[node*2]&seg[node*2+1];
}
long query(long node,long lo,long hi,long lt,long rt)
{
  if(lo>rt||hi<lt)return (1<<60)-1;
  if(lo>=lt&&hi<=rt)return seg[node];
  long md=(lo+hi)/2;
  return query(node*2,lo,md,lt,rt)&query(node*2+1,md+1,hi,lt,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>arr[i],arr[n+i]=arr[i],arr[n+n+i]=arr[i];
    build(1LL,1LL,3*n);

    for(int i=1;i<=n;i++)
    {
      id=n+i;
      lft=max(1LL,id-k);
      rgt=min(3*n,id+k);
      cout<<query(1,1,3*n,lft,rgt)<<" ";
    }
    cout<<endl;
  }
  return 0;
}