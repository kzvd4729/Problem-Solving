/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/05/2020 21:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/1442/problem/B
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
const int N=2e5,mod=998244353;
int a[N+2],b[N+2],po[N+2],rl[N+2],l[N+2],r[N+2];
int getLft(int x)
{
  if(x==l[x])return x;
  return l[x]=getLft(l[x]);
}
int getRgt(int x)
{
  if(x==r[x])return x;
  return r[x]=getRgt(r[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i],po[a[i]]=i,rl[i]=1;
    for(int i=1;i<=k;i++)cin>>b[i],rl[b[i]]=0;
     a[0]=0;a[n+1]=n+1;rl[n+1]=0;rl[0]=0;
     for(int i=1;i<=n;i++)l[i]=i;l[0]=0;
    for(int i=1;i<=n;i++)r[i]=i;r[n+1]=n+1;
     int ans=1;
    for(int i=1;i<=k;i++)
    {
      int id=po[b[i]],dl;
      int ld=getLft(id-1),rd=getRgt(id+1);
       //cout<<ld<<" "<<rd<<endl;
       if(rl[a[ld]]&&rl[a[rd]])
      {
        ans=(ans*2)%mod;dl=rd;
      }
      else if(rl[a[ld]])dl=ld;
      else if(rl[a[rd]])dl=rd;
      else {ans=0;break;}
       rl[b[i]]=1;r[dl]=dl+1;l[dl]=dl-1;
    }
    cout<<ans<<" ";
  }
  cout<<endl;
  return 0;
}