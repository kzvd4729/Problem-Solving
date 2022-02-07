/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-15 20:49:34                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 2120                                            memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11858
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
int pos[N+2],bit[N+2],n;
map<long,int>mp;long aa[N+2],bb[N+2];
void upd(int id)
{
  for( ;id<=n;id+=(id&-id))
    bit[id]++;
}
int get(int id)
{
  int ret=0;
  for( ;id>0;id-=(id&-id))
    ret+=bit[id];
  return ret;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  while(cin>>n)
  {
    for(int i=1;i<=n;i++)bit[i]=0;
    for(int i=1;i<=n;i++)
    {
      cin>>aa[i];bb[i]=aa[i];
    }
    mp.clear();
    sort(bb+1,bb+n+1);
    for(int i=1;i<=n;i++)
      mp[bb[i]]=i;
    for(int i=1;i<=n;i++)
    {
      int x=mp[aa[i]];pos[x]=i;
    }
    long ans=0;
    for(int i=n;i>=1;i--)
    {
      int ps=pos[i]-get(pos[i]);
      ans+=(i-ps)*1LL;upd(pos[i]);
    }
    cout<<ans<<endl;
  }
  return 0;
}