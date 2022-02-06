/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/29/2020 17:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 57100 KB                             
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
pair<int,int>ans[N+2],tmp[N+2];
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
  map<int,vector<int> >mp1,mp2;vector<int>v;
  for(int i=a;i>=1;i--)mp1[aa[i].p-aa[i].t].push_back(i),v.push_back(aa[i].p-aa[i].t);
  for(int i=1;i<=b;i++)mp2[bb[i].p-bb[i].t].push_back(i),v.push_back(bb[i].p-bb[i].t);
  sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
  
  for(auto d:v)
  {
    int id=0;
    for(auto x:mp2[d])tmp[++id]={w,bb[x].p};
    for(auto x:mp1[d])tmp[++id]={aa[x].p,h};

    id=0;
    for(auto x:mp1[d])ans[aa[x].id]=tmp[++id];
    for(auto x:mp2[d])ans[bb[x].id]=tmp[++id];
  }
  for(int i=1;i<=n;i++)cout<<ans[i].first<<" "<<ans[i].second<<"\n";
  return 0;
}