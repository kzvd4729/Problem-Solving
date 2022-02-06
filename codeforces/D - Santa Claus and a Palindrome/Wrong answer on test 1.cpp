/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/06/2019 12:59                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/752/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
map<string,vector<int> >pl,st;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int k,n;cin>>k>>n;
  for(int i=1;i<=k;i++)
  {
    string a,b;cin>>b;int x;cin>>x;
    a=b;reverse(b.begin(),b.end());
    if(a==b)
      pl[a].push_back(x);
    else
      st[a].push_back(x);
  }
  long ans=0,ex=0;
  for(auto x:st)
  {
    string s=x.first;reverse(s.begin(),s.end());
    vector<int>a=x.second,b=st[s];
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    //for(auto x:a)cout<<x<<" ";cout<<endl;
    //for(auto x:b)cout<<x<<" ";cout<<endl;
    int mn=min((int)a.size(),(int)b.size());
    for(int i=0;i<mn;i++)
      ans+=max(0,a[i]+b[i])*1LL;
  }
  ans/=2;
  for(auto x:pl)
  {
    vector<int>a=x.second;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    if(a.size()%2)
    {
      for(int i=0;i<a.size()-1;i+=2)
        ans+=max(0LL,(a[i]+a[i+1])*1LL);
      ex=max(ex,a[a.size()-1]*1LL);
    }
    else
    {
      for(int i=0;i<a.size();i++)
        ans+=max(0LL,(a[i]+a[i+1])*1LL);
    }
  }
  cout<<ans+ex<<endl;
  return 0;
}