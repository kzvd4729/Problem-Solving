/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/07/2018 14:41                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/547/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long m,h1,a1,x1,y1,h2,a2,x2,y2;
int l1,l2,c1,c2;
map<long,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
   for(int i=0; ;i++)
  {
    if(h1==a1)l1=i;
    if(mp[h1])
    {
      c1=i-mp[h1];
      break;
    }
    mp[h1]=i;
    h1=(h1*x1+y1)%m;
  }
  if(!l1)cout<<-1<<endl,exit(0);
  mp.clear();
  for(int i=0; ;i++)
  {
    if(h2==a2)l2=i;
    if(mp[h2])
    {
      c2=i-mp[h2];
      break;
    }
    mp[h2]=i;
    h2=(h2*x2+y2)%m;
  }
  if(!l2)cout<<-1<<endl,exit(0);
   if(c1<c2)
  {
    swap(l1,l2);
    swap(c1,c2);
  }
   long in=l1;
  for(int i=1;i<=1000000;i++)
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