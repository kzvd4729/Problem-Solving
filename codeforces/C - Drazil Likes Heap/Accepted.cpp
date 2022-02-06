/****************************************************************************************
*  @author: kzvd4729                                         created: May/03/2020 20:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 638 ms                                          memory_used: 45300 KB                             
*  problem: https://codeforces.com/contest/1329/problem/C
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
#define long long long
using namespace std;
const int N=5e6,mod=1e9+9;
int aa[N+2],bb[N+2],n,g;
vector<int>bf;
void del(int id)
{
  int l=2*id,r=2*id+1;
  bf.push_back(id);bb[id]=aa[id];
  if(aa[l]==0&&aa[r]==0)
  {
    aa[id]=0;return ;
  }
  if(aa[l]>aa[r])
  {
    aa[id]=aa[l];del(l);
  }
  else 
  {
    aa[id]=aa[r],del(r);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,g;cin>>n>>g;n=(1<<n)-1,g=(1<<g)-1;
    for(int i=1;i<=4*n;i++)aa[i]=0;
    for(int i=1;i<=n;i++)cin>>aa[i];vector<int>pr;
    for(int i=1;i<=n;i++)
    {
      bf.clear();del(i);int f=0;
      for(auto x:bf)if(x<=g&&aa[x]==0)f=1;
      if(f)for(auto x:bf)aa[x]=bb[x];
      else i--,n--,pr.push_back(i+1);
      if(n==g)break;
    }
    long ans=0;
    for(int i=1;i<=g;i++)ans+=aa[i];cout<<ans<<"\n";
    for(auto x:pr)cout<<x<<" ";cout<<"\n";
  }
  return 0;
}