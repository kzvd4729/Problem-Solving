/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2020 19:28                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/611/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],cnt[3+2],n,a,b,c;
bool ck(int md)
{
  int ca=cnt[1],cb=cnt[2],cc=cnt[3];
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
   int id=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(x<=c){aa[++id]=x;continue;}
     if(x<=a+b)cnt[1]++,cnt[2]++;
    else if(x<=a+c)cnt[1]++,cnt[3]++;
    else if(x<=b+c)cnt[2]++,cnt[3]++;
    else if(x<=a+b+c)cnt[1]++,cnt[2]++,cnt[3]++;
    else cout<<-1<<endl,exit(0);
  }
  n=id;sort(aa+1,aa+n+1);
  int lo=max({cnt[1],cnt[2],cnt[3]}),hi=2e5,md,ans;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ck(md))hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)
    if(ck(md))cout<<md<<endl,exit(0);
  return 0;
}