/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/21/2019 18:53                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 60 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/149/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>zfunction(string s)
{
  int n=s.size();vector<int>z(n);
  z[0]=0;//l,r maintains a window with maximum r
  for(int i=1,l=0,r=0;i<n;i++)
  {
    if(i<=r)z[i]=min(r-i+1,z[i-l]);//inside the window
    while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;//brute-force
    if(i+z[i]-1>r)l=i,r=i+z[i]-1;//r update
  }
  return z;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string r,s;cin>>r;s=r;reverse(r.begin(),r.end());
  int q;cin>>q;int ans=0;
  while(q--)
  {
    string tmp,tmpr;cin>>tmp;tmpr=tmp;
    if(tmp.size()==1)continue;
    reverse(tmpr.begin(),tmpr.end());
    vector<int>a=zfunction(tmp+"#"+s);
     vector<int>b=zfunction(tmpr+"#"+r);
     vector<int>c((int)s.size()+1,0);int id=s.size()-1;
    for(int i=tmp.size()+1;i<=tmp.size()+s.size();i++)
    {
      c[id]=b[i];id--;
    }
    for(int i=0;i<s.size();i++)
    {
      c[i-c[i]]=max(c[i],c[i-c[i]]);
      c[i]=0;
    }
    for(int i=s.size()-1;i>=0;i--)
      c[i]=max(c[i],c[i+1]);
    id=0;
    for(int i=tmp.size()+1;i<=tmp.size()+s.size();i++)
    {
      if(a[i]+c[id+a[i]]>=tmp.size())
      {
        //cout<<id<<endl;
        ans++;break;
      }
      id++;
    }
  }
  cout<<ans<<endl;
  return 0;
}