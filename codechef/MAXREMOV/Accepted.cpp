/****************************************************************************************
*  @author: kzvd4729                                         created: 17-02-2019 22:15:03                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.21 sec                                        memory_used: 17.2M                                
*  problem: https://www.codechef.com/COOK103A/problems/MAXREMOV
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int lo[N+2],hi[N+2];
/*************** BIT *****************/
int Bit[N+2];
void Upd(int x,int vl)
{
  for( ;x<=N;x+=(x&-x))
    Bit[x]+=vl;
}
int Sum(int x)
{
  int sum=0;
  for( ;x>0;x-=(x&-x))
    sum+=Bit[x];
  return sum;
}
////////////////////////////////////////
int bit[N+2];
void upd(int x,int vl)
{
  for( ;x<=N;x+=(x&-x))
    bit[x]+=vl;
}
int sum(int x)
{
  int sum=0;
  for( ;x>0;x-=(x&-x))
    sum+=bit[x];
  return sum;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    memset(Bit,0,sizeof(Bit));
    memset(bit,0,sizeof(bit));
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
      int x,y;cin>>x>>y;lo[i]=x;hi[i]=y;
      Upd(x,1);Upd(y+1,-1);
    }
    int tot=0;
    for(int i=1;i<=N;i++)
    {
      int xx=Sum(i);
      if(xx==k)upd(i,-1),tot++;
      if(xx==k+1)upd(i,1);
    }
    int mx=0;
    for(int i=1;i<=n;i++)
      mx=max(mx,tot+sum(hi[i])-sum(lo[i]-1));
    cout<<mx<<"\n";
  }
  return 0;
}