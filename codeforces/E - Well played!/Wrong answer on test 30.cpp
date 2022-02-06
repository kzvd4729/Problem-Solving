/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/30/2018 22:30                        
*  solution_verdict: Wrong answer on test 30                 language: GNU C++14                               
*  run_time: 311 ms                                          memory_used: 18900 KB                             
*  problem: https://codeforces.com/contest/976/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long n,a,b;
struct data
{
  long hl,dm;
}arr[N+2],seg[4*N];
bool cmp(data A,data B)
{
  return (A.hl-A.dm)>(B.hl-B.dm);
}
long mul(long x)
{
  for(int i=1;i<=a;i++)
    x*=2;
  return x;
}
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node].hl=arr[lo].hl;
    seg[node].dm=arr[lo].dm;
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);
  seg[node].hl=seg[node*2].hl+seg[node*2+1].hl;
  seg[node].dm=seg[node*2].dm+seg[node*2+1].dm;
}
data query(int node,int lo,int hi,int l,int r)
{
  if(lo>r||hi<l)return {0,0};
  if(lo>=l&&hi<=r)return seg[node];
  int md=(lo+hi)/2;
  data p1=query(node*2,lo,md,l,r);
  data p2=query(node*2+1,md+1,hi,l,r);
  return {p1.hl+p2.hl,p1.dm+p2.dm};
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>a>>b;
  for(int i=1;i<=n;i++)
    cin>>arr[i].hl>>arr[i].dm;
  sort(arr+1,arr+n+1,cmp);
   build(1,1,N);
   int idd;
  long dmg=0,ans=0,dmgg=0;
  for(int i=1;i<=n;i++)
  {
    if(arr[i].hl>arr[i].dm)idd=i;
    dmgg+=arr[i].dm;
  }
  ans=dmgg;
  for(int i=n;i>=1;i--)
  {
    arr[i].hl=mul(arr[i].hl);
    int bb=b,x,xx,l,r;
    dmg=dmgg;
      if(bb)
    {
      if(arr[i].hl>arr[i].dm)
      {
        dmg+=arr[i].hl;
        dmg-=arr[i].dm;
        bb--;
      }
      l=1;
      r=min(i-1,idd);
      r=min(r,bb);
      bb-=(r-l+1);
      if(r>=l)
      {
        data xx=query(1,1,N,l,r);
        dmg+=(xx.hl-xx.dm);
      }
    }
    if(bb)
    {
      l=min(i+1,idd+1);
      r=idd;
      r=min(r,l+bb-1);
      if(r>=l)
      {
        data xx=query(1,1,N,l,r);
        dmg+=(xx.hl-xx.dm);
      }
    }
    ans=max(ans,dmg);
  }
  cout<<ans<<endl;
  return 0;
}