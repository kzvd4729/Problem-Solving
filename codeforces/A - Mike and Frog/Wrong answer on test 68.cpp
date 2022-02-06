/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/07/2018 15:08                        
*  solution_verdict: Wrong answer on test 68                 language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 8100 KB                              
*  problem: https://codeforces.com/contest/547/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long m,h1,a1,x1,y1,h2,a2,x2,y2;
long l1,l2,c1,c2,f;
long mp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
 //  long hh=h1,hhh=h2;
//  for(int i=1;i<=1000000;i++)
//  {
//    cout<<hh<<" "<<a1<<" "<<hhh<<" "<<a2<<endl;
//    getchar();
//    hh=(hh*x1+y1)%m;
//    hhh=(hhh*x2+y2)%m;
//  }
  //memset(mp,-1,sizeof(mp));
  for(long i=0; ;i++)
  {
    if(mp[h1])
    {
      c1=i-mp[h1];
      if(mp[h1]>l1)f=1;
      break;
    }
    if(h1==a1)l1=i;
    mp[h1]=i;
    h1=(h1*x1+y1)%m;
  }
  memset(mp,0,sizeof(mp));
  for(long i=0; ;i++)
  {
    if(mp[h2])
    {
      c2=i-mp[h2];
      if(mp[h2]>l2)f=1;
      break;
    }
    if(h2==a2)l2=i;
    mp[h2]=i;
    h2=(h2*x2+y2)%m;
  }
  if(l1==l2&&l1)cout<<l1<<endl,exit(0);
  if(f)cout<<-1<<endl,exit(0);
  if(c1<c2)
  {
    swap(l1,l2);
    swap(c1,c2);
  }
  long in=l1;
  for(long i=1;i<=1000000;i++)
  {
    if(in>=l2)
    {
      if((in-l2)%c2==0)
        cout<<in<<endl,exit(0);
    }
    in+=c1;
  }
  cout<<-1<<endl;
   return 0;
}