/****************************************************************************************
*  @author: kzvd4729                                         created: May/05/2020 21:23                        
*  solution_verdict: Time limit exceeded on test 10          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 7100 KB                              
*  problem: https://codeforces.com/contest/877/problem/F
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
#include<ext/pb_ds/assoc_container.hpp>
#define long long long
using namespace std;
using namespace __gnu_pbds;
const int N=1e5,mod=1e9+7;
int ty[N+2],aa[N+2],bl[N+2],k;
unordered_map<long,int>mp,an;long ans[N+2];
int brut(int l,int r,int f)
{
  int ret=0;long pr=0,sm=0;
  for(int i=l;i<=r;i++)pr+=aa[i];
  an.clear();an[0]=1;mp[0]-=f;
  ret=mp[-k-pr];
  for(int i=l;i<=r;i++)
  {
    sm+=aa[i];
    if(an.count(sm+k))ret+=an[sm+k];
    if(i<r&&f&&mp.count(sm-k-pr))ret+=mp[sm-k-pr];
    an[sm]++;
  }
  mp[0]+=f;return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  mp.reserve((1<<17));mp.max_load_factor(0.25);
  an.reserve((1<<17));an.max_load_factor(0.25);
  int n;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>ty[i];
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];if(ty[i]==1)aa[i]*=-1;
  }
  //for(int i=1;i<=n;i++)cout<<aa[i]<<" ";cout<<endl;
  int magic=100;
  for(int i=1;i<=n;i++)bl[i]=i/magic+1;
  int q;cin>>q;vector<vector<int> >qr;
  for(int i=1;i<=q;i++)
  {
    int u,v;cin>>u>>v;
    if(bl[u]==bl[v])ans[i]=brut(u,v,0);
    else qr.push_back({u,v,i});
  }
  sort(qr.begin(),qr.end(),[&](vector<int>a,vector<int>b){
    if(bl[a[0]]!=bl[b[0]])return a[0]<b[0];
    return a[1]<b[1];
  });
  int pt=0;
  for(int b=1; ;b++)
  {
    if(pt==qr.size())break;
    int l=(b-1)*magic,r=b*magic-1;
    if(qr[pt][0]>r)continue;
    if(l==0)l=1;if(r>n)r=n;
        mp.clear();mp[0]=1;long sm=0,now=0;
    for(int i=r+1;i<=n;i++)
    {
      if(pt==qr.size()||qr[pt][0]>r)break;
      sm+=aa[i];if(mp.count(sm+k))now+=mp[sm+k];
      mp[sm]++;
      while(pt<qr.size()&&i==qr[pt][1]&&qr[pt][0]<=r)
      {
        //cout<<"Now "<<now<<endl;
        ans[qr[pt][2]]=now+brut(qr[pt][0],r,1);
        pt++;
      }
    }
    if(r==n)break;
  }
  for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
  return 0;
}