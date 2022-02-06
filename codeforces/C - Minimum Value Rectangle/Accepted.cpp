/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/21/2018 10:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1060 ms                                         memory_used: 700 KB                               
*  problem: https://codeforces.com/contest/1027/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
vector<int>vv;
int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
  int t;cin>>t;
 while(t--)
 {
  int n,x;cin>>n;map<int,int>mp;
  for(int i=1;i<=n;i++)cin>>x,mp[x]++;
  map<int,int>::iterator it;vv.clear();
  for(it=mp.begin();it!=mp.end();it++)
  {
   if(it->second>=4)vv.push_back(it->first);
   if(it->second>=2)vv.push_back(it->first);
  }
  double ans=1e14;int r,c;
  for(int i=0;i<vv.size()-1;i++)
  {
   int lo=i+1,hi=vv.size()-1,md1,md2;
   while(hi-lo>3)
   {
    md1=(lo+lo+hi)/3;
    double vl1=((vv[i]+vv[md1])*1.00*(vv[i]+vv[md1]))/(vv[i]*1.0*vv[md1]);
    md2=(lo+hi+hi)/3;
    double vl2=((vv[i]+vv[md2])*1.00*(vv[i]+vv[md2]))/(vv[i]*1.0*vv[md2]);
    if(md2<md1)lo=md1;
    else hi=md2;
   }
   for(int md=lo;md<=hi;md++)
   {
    double vl=((vv[i]+vv[md])*1.00*(vv[i]+vv[md]))/(vv[i]*1.0*vv[md]);
    if(vl<ans)
    {
     ans=vl;
     r=vv[i];c=vv[md];
    }
   }
  }
  cout<<r<<" "<<r<<" "<<c<<" "<<c<<endl;
 } 
 return 0;
}