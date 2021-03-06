/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 186 ms                                          memory_used: 4000 KB                              
*  problem: https://codeforces.com/contest/85/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long k1,k2,k3;cin>>k1>>k2>>k3;
  long t1,t2,t3;cin>>t1>>t2>>t3;
   long n;cin>>n;
  for(long i=1;i<=n;i++)cin>>aa[i],bb[i]=aa[i];
  multiset<long>st;vector<long>v;
    for(long i=1;i<=n;i++)
  {
    while(true)
    {
      if(st.size()==0)break;
      long x=*st.begin();
      if(x<aa[i])st.erase(st.find(x));
      else break;
    }
    if(st.size()<k1)
    {
      st.insert(aa[i]+t1-1);
      v.push_back(aa[i]+t1);
    }
    else
    {
      long x=*st.begin();
      st.erase(st.find(x));
      st.insert(x+t1);
      v.push_back(x+t1+1);
    }
  }
   for(long i=1;i<=n;i++)
    aa[i]=v[i-1];
  v.clear();st.clear();
  //sort(aa+1,aa+n+1);
     for(long i=1;i<=n;i++)
  {
    while(true)
    {
      if(st.size()==0)break;
      long x=*st.begin();
      if(x<aa[i])st.erase(st.find(x));
      else break;
    }
    if(st.size()<k2)
    {
      st.insert(aa[i]+t2-1);
      v.push_back(aa[i]+t2);
    }
    else
    {
      long x=*st.begin();
      st.erase(st.find(x));
      st.insert(x+t2);
      v.push_back(x+t2+1);
    }
  }
  for(long i=1;i<=n;i++)
    aa[i]=v[i-1];
  v.clear();st.clear();
  //sort(aa+1,aa+n+1);
     for(long i=1;i<=n;i++)
  {
    while(true)
    {
      if(st.size()==0)break;
      long x=*st.begin();
      if(x<aa[i])st.erase(st.find(x));
      else break;
    }
    if(st.size()<k3)
    {
      st.insert(aa[i]+t3-1);
      v.push_back(aa[i]+t3);
    }
    else
    {
      long x=*st.begin();
      st.erase(st.find(x));
      st.insert(x+t3);
      v.push_back(x+t3+1);
    }
  }
   for(long i=1;i<=n;i++)
    aa[i]=v[i-1];
  v.clear();st.clear();
  //sort(aa+1,aa+n+1);
   long mx=0;
  for(long i=1;i<=n;i++)
    mx=max(mx,aa[n]-bb[n]);
  cout<<mx<<endl;
  return 0;
}