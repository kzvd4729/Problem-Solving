/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-10-24 19:03:46                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1085
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int mod=1000000007;
const int N=1e5;
int t,tc,n,xx,bit[N+2],x,arr[N+2],tmp[N+2],cnt;
map<int,int>mp;
void upd(int idx,int vl)
{
  for( ;idx<=n;idx+=idx&-idx)bit[idx]=(bit[idx]+vl)%mod;
}
int query(int idx)
{
  int sum=0;
  for( ;idx>0;idx-=idx&-idx)sum=(sum+bit[idx])%mod;
  return sum;
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&arr[i]);
      tmp[i]=arr[i];
    }
    sort(tmp,tmp+n+1);
    cnt=0;
    mp.clear();
    for(int i=1;i<=n;i++)if(!mp[tmp[i]])mp[tmp[i]]=++cnt;
    memset(bit,0,sizeof(bit));
    for(int i=1;i<=n;i++)
    {
      xx=query(mp[arr[i]]-1);
      upd(mp[arr[i]],xx+1);
    }
    printf("Case %d: %d\n",++tc,query(n));
  }
  return 0;
}