/****************************************************************************************
*  @author: kzvd4729                                         created: 11-11-2018 15:55:13                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.10 sec                                        memory_used: 22.5M                                
*  problem: https://www.codechef.com/problems/REBXOR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e5;
int sz,aa[N+2],tr[N+2][2],frnt[N+2],back[N+2];
void insrt(int x)
{
  int now=0;
  for(int i=30;i>=0;i--)
  {
    bool z=(x&(1<<i));
    if(!tr[now][z])tr[now][z]=++sz;
    now=tr[now][z];
  }
}
int qry(int x)
{
  int now=0,ret=0;
  for(int i=30;i>=0;i--)
  {
    bool z=(x&(1<<i));
    if(tr[now][!z])
    {
      now=tr[now][!z];ret|=(1<<i);
    }
    else now=tr[now][z];
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  int xxr=0;insrt(xxr);
  for(int i=1;i<=n;i++)
  {
    xxr^=aa[i];
    frnt[i]=max(frnt[i-1],qry(xxr));insrt(xxr);
  }
  // for(int i=1;i<=n;i++)
  //   cout<<frnt[i]<<" ";
  // cout<<endl;
  sz=0;memset(tr,0,sizeof(tr));
  xxr=0;insrt(xxr);
  for(int i=n;i>=1;i--)
  {
    xxr^=aa[i];
    back[i]=max(back[i+1],qry(xxr));insrt(xxr);
  }
  int ans=0;
  for(int i=0;i<=n;i++)
    ans=max(ans,frnt[i]+back[i+1]);
  cout<<ans<<endl;
  return 0;
}