/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/02/2019 17:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 9400 KB                              
*  problem: https://codeforces.com/contest/750/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<pair<int,int> >v;
  for(int i=1;i<=n;i++)cin>>aa[i]>>bb[i];
  for(int i=1;i<=n; )
  {
    int sm=aa[i],cnt=1;
    if(bb[i]==1)
    {
      int mn=1e9;
      for(int j=i+1;j<=n;j++)
      {
        if(bb[j]!=bb[i])break;
        mn=min(mn,sm);sm+=aa[j];
        cnt++;
      }
      v.push_back({mn,sm});
    }
    else
    {
      int mx=-1e9;
      for(int j=i+1;j<=n;j++)
      {
        if(bb[j]!=bb[i])break;
        mx=max(mx,sm);sm+=aa[j];
        cnt++;
      }
      v.push_back({mx,sm});
    }
    i+=cnt;
  }
  int f=0;if(bb[1]==2)f=1;
  int mn=-1e9,mx=1e9;
  for(int i=0;i<v.size();i++)
  {
    if(!f)
    {
      int mxh=1900-v[i].second-1;
      int mnh=1900-v[i].first;
      if(mnh<1900)mnh=1900;
      if(i==v.size()-1)mxh=1e9;
      mn=max(mn,mnh),mx=min(mx,mxh);
    }
    else
    {
      int mnh=1900-v[i].second;
      int mxh=1900-v[i].first-1;
      if(mxh>=1900)mxh=1899;
      if(i==v.size()-1)mnh=-1e9;
      mn=max(mn,mnh),mx=min(mx,mxh);
    }
    //cout<<mn<<" -- "<<mx<<endl;
    f^=1;mn+=v[i].second,mx+=v[i].second;
  }
  if(mx>1e8)cout<<"Infinity"<<endl;
  else if(mn>mx)cout<<"Impossible"<<endl;
  else cout<<mx<<endl;
  return 0;
}