/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/19/2018 00:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/1054/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int ans[N+2],n;
struct data
{
  int a,b,c;
}aa[N+2];
bool cmp(data A,data B)
{
  return A.a+A.b<B.a+B.b;
}
bool cpm(data A,data B)
{
  return A.c<B.c;
}
void inv(void)
{
  cout<<"NO"<<endl,exit(0);
}
void ck(void)
{
  for(int i=1;i<=n;i++)
  {
    if(!ans[i])inv();int cnt=0;
    for(int j=i+1;j<=n;j++)
    {
      if(ans[j]>ans[i])cnt++;
    }
    if(cnt!=aa[i].b)inv();
    cnt=0;
    for(int j=i-1;j>=1;j--)
    {
      if(ans[j]>ans[i])cnt++;
    }
    if(cnt!=aa[i].a)inv();
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i].a;
    aa[i].c=i;
  }
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i].b;
  }
  sort(aa+1,aa+n+1,cmp);
   int pl=n,now=0,cnt=1;
  if(aa[1].a+aa[1].b)inv();
  for(int i=2;i<=n;i++)
  {
    if(aa[i].a+aa[i].b==now)cnt++;
    else
    {
      for(int j=i-1;j>=i-cnt;j--)
        ans[aa[j].c]=pl;
      pl--;cnt=1;now=aa[i].a+aa[i].b;
    }
  }
  for(int i=n;i>=n-cnt+1;i--)
    ans[aa[i].c]=pl;
  sort(aa+1,aa+n+1,cpm);
  ck();cout<<"YES"<<endl;
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}