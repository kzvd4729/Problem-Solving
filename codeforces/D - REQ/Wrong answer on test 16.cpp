/****************************************************************************************
*  @author: kzvd4729                                         created: May/05/2020 11:17                        
*  solution_verdict: Wrong answer on test 16                 language: GNU C++14                               
*  run_time: 2589 ms                                         memory_used: 59900 KB                             
*  problem: https://codeforces.com/contest/594/problem/D
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
#define long long long
using namespace std;
const int N=2e5,R=1e6,mod=1e9+7;
int inv[R+2],cl[R+2];
void modI(void)
{
  inv[1]=1;
  for(int i=2;i<=R;i++)
    inv[i]=(mod-(1LL*(mod/i)*inv[mod%i])%mod)%mod;
  for(int i=1;i<=R;i++)
    cl[i]=(1LL*(i-1)*inv[i])%mod;
}
int vs[R+2];
vector<int>fc[R+2],pr;
void fact()
{
  for(int i=2;i<=R;i++)
  {
    if(vs[i])continue;pr.push_back(i);
    for(int j=i;j<=R;j+=i)
      vs[j]=1,fc[j].push_back(i);
  }
}
int aa[N+2],bln[N+2],ans[N+2],con[R+2],fr[N+2];
long brut(long ml,int l,int r)
{
  for(int i=l;i<=r;i++)
  {
    ml=(ml*aa[i])%mod;
    for(auto x:fc[aa[i]])
    {
      int id=con[x];
      fr[id]++;if(fr[id]==1)ml=(ml*cl[x])%mod;
    }
  }
  for(int i=l;i<=r;i++)
  {
    for(auto x:fc[aa[i]])
      fr[con[x]]--;
  }
  return ml;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  modI();fact();
  for(int i=0;i<pr.size();i++)con[pr[i]]=i;
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   int magic=100;
  for(int i=1;i<=n;i++)bln[i]=i/magic+1;
   int q;cin>>q;vector<vector<int> >qr;int qq=q;
  for(int i=1;i<=q;i++)
  {
    int u,v;cin>>u>>v;
    if(bln[u]==bln[v])ans[i]=brut(1,u,v);
    else qr.push_back({u,v,i});
  }
  sort(qr.begin(),qr.end(),[&](vector<int>&a,vector<int>&b){
    if(bln[a[0]]!=bln[b[0]])return a[0]<b[0];
    return a[1]<b[1];
  });
  int pt=0;q=qr.size();
  for(int b=1; ;b++)
  {
    int l=(b-1)*magic,r=b*magic-1;
    if(l==0)l=1;if(r>n)r=n;
    if(pt==q)break;
    if(qr[pt][0]>r)continue;
     long ml=1;memset(fr,0,sizeof fr);
    for(int i=r+1;i<=n;i++)
    {
      if(pt==q||qr[pt][0]>r)break;      
      ml=(ml*aa[i])%mod;
      for(auto x:fc[aa[i]])
      {
        int id=con[x];
        fr[id]++;if(fr[id]==1)ml=(ml*cl[x])%mod;
      }
      while(pt<q&&qr[pt][1]==i)
      {
        ans[qr[pt][2]]=brut(ml,qr[pt][0],r),pt++;
      }
    }
    if(r==n)break;
  }
  for(int i=1;i<=qq;i++)cout<<ans[i]<<"\n";
  return 0;
}