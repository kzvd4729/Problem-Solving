/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/11/2020 14:00                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/623/problem/B
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
const int N=1e6;
vector<int>v;
void cal(int x)
{
  int sq=sqrt(x+1);
  for(int i=2;i<=sq;i++)
  {
    if(x%i)continue;v.push_back(i);
    while(x%i==0)x/=i;
  }
  if(x>1)v.push_back(x);
}
int aa[N+2],bb[N+2],n,a,b;
long ok(int p)
{
  for(int i=1;i<=n;i++)
  {
    int md=aa[i]%p;
    if(md==0)bb[i]=0;
    else if(md==1||md==p-1)bb[i]=b;
    else bb[i]=-1;
  }
  int fr=-1,ls=-1;
  for(int i=1;i<=n;i++)
  {
    if(bb[i]==-1&&fr==-1)fr=i;
    if(bb[i]==-1)ls=i;
  }
  //for(int i=1;i<=n;i++)cout<<bb[i]<<" ";cout<<endl;
  long ret=0;
  if(fr!=-1)
  {
    for(int i=1;i<fr;i++)ret+=bb[i];
    for(int i=ls+1;i<=n;i++)ret+=bb[i];
    ret+=a*(ls-fr+1);
     for(int i=1;i<fr;i++)bb[i]=bb[i]-a;
    for(int i=ls+1;i<=n;i++)bb[i]=bb[i]-a;
     long mxl=0,mxr=0,sml=0,smr=0;
    for(int i=fr-1;i>1;i--)
    {
      sml+=bb[i];
      mxl=max(mxl,sml);
    }
    if(fr!=1)sml+=bb[1];
    for(int i=ls+1;i<n;i++)
    {
      smr+=bb[i];
      mxr=max(mxr,smr);
    }
    if(ls!=n)smr+=bb[n];
    long mx=mxl+mxr;
    if(fr>1)mx=max(mx,mxl+smr);
    if(ls<n)mx=max(mx,mxr+sml);
    return ret-mx;
  }
  else
  {
    for(int i=1;i<=n;i++)ret+=bb[i];
    for(int i=1;i<=n;i++)bb[i]=bb[i]-a;
     long mx=0,now=0;
    for(int i=2;i<n;i++)
    {
      now+=bb[i];
      if(now<0)now=0;mx=max(mx,now);
    }
    long sm=0;
    for(int i=1;i<n;i++)
    {
      sm+=bb[i];mx=max(mx,sm);
    }
    sm=0;
    for(int i=n;i>1;i--)
    {
      sm+=bb[i];mx=max(mx,sm);
    }
    return ret-mx;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>a>>b;
  for(int i=1;i<=n;i++)cin>>aa[i];
  cal(aa[1]);cal(aa[1]+1);cal(aa[1]-1);
  cal(aa[n]);cal(aa[n]+1);cal(aa[n]-1);
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  long ans=1e18;
  //cout<<ok(2)<<endl;exit(0);
  for(auto x:v)ans=min(ans,ok(x));
  cout<<ans<<endl;
   return 0;
}