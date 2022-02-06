/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/29/2020 17:01                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 39100 KB                             
*  problem: https://codeforces.com/contest/848/problem/B
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
#define long long long
using namespace std;
const int N=1e6;
pair<int,int>ans[N+2];
struct data
{
  int g,p,t,id;
}aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,w,h;cin>>n>>w>>h;int a=0,b=0;
  for(int i=1;i<=n;i++)
  {
    int g,p,t;cin>>g>>p>>t;
    if(g==1)aa[++a]={g,p,t,i};
    else bb[++b]={g,p,t,i};
  }
  sort(aa+1,aa+a+1,[](data a,data b){
    return a.p<b.p;
  });
  sort(bb+1,bb+b+1,[](data a,data b){
    return a.p<b.p;
  });
  map<int,int>mp;
  for(int i=1;i<=b;i++)mp[bb[i].p-bb[i].t]=i;
  for(int i=1;i<=a;i++)
  {
    if(mp.count(aa[i].p-aa[i].t))
    {
      int sw=mp[aa[i].p-aa[i].t];//cout<<i<<" ** "<<sw<<endl;
      swap(aa[i].id,bb[sw].id);
    }
    ans[aa[i].id]={aa[i].p,h};
  }
  for(int i=1;i<=b;i++)ans[bb[i].id]={w,bb[i].p};
  for(int i=1;i<=n;i++)cout<<ans[i].first<<" "<<ans[i].second<<"\n";
  return 0;
}