/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2020 19:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 108 ms                                          memory_used: 2400 KB                              
*  problem: https://codeforces.com/contest/611/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],cnt[3+2],n,a,b,c;
bool ck(int md)
{
  int ca=0,cb=0,cc=0;
  for(int i=n;i>=1;i--)
  {
    if(cc<md){cc++;continue;}
    if(aa[i]>a+b)return false;
     if(aa[i]<=b&&cb<md){cb++;continue;}
    if(aa[i]<=a&&ca<md){ca++;continue;}
     if(ca<md&&cb<md)ca++,cb++;
    else return false;
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>a>>b>>c;
   if(a>b)swap(a,b);if(a>c)swap(a,c);if(b>c)swap(b,c);
   int id=0,ans=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(x<=c){aa[++id]=x;continue;}
     if(x<=a+b)cnt[3]++;else if(x<=a+c)cnt[2]++;
    else if(x<=b+c)cnt[1]++;else if(x<=a+b+c);
    else cout<<-1<<endl,exit(0);
    ans++;
  }
  n=id;sort(aa+1,aa+n+1);vector<int>v;
  for(int i=n;i>=1;i--)
  {
    if(aa[i]<=c&&cnt[3]){cnt[3]--;continue;}
    if(aa[i]<=b&&cnt[2]){cnt[2]--;continue;}
    if(aa[i]<=a&&cnt[1]){cnt[1]--;continue;}
    v.push_back(aa[i]);
  }
  n=v.size();for(int i=1;i<=n;i++)aa[i]=v[i-1];
  sort(aa+1,aa+n+1);
  int lo=0,hi=2e5,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ck(md))hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)
    if(ck(md))cout<<ans+md<<endl,exit(0);
  return 0;
}