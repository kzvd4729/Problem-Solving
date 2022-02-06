/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/21/2019 19:26                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/149/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>zFunction(string s)
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
vector<int>prefixFunction(string s)
{
  int n=s.size();vector<int>pi(n);
  for(int i=1;i<n;i++)
  {
    int j=pi[i-1];
    while(j>0&&s[i]!=s[j])j=pi[j-1];
    if(s[i]==s[j])j++;pi[i]=j;
  }
  return pi;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int q,ans=0;cin>>q;
  string r=s;reverse(r.begin(),r.end());
  while(q--)
  {
    string tmp;cin>>tmp;if(tmp.size()==1)continue;
    string tmpr=tmp;reverse(tmpr.begin(),tmpr.end());
     vector<int>a=zFunction(tmp+"#"+s);
    vector<int>b=prefixFunction(tmpr+"#"+r);
     vector<int>c;
    for(int i=b.size()-1;c.size()!=s.size();i--)
      c.push_back(b[i]);
    for(int i=c.size()-2;i>=0;i--)
      c[i]=max(c[i],c[i+1]);
    int id=0;
    for(int i=tmp.size()+1;i<=tmp.size()+s.size();i++)
    {
      if(a[i]+c[id+a[i]]>=tmp.size())
      {
        ans++;break;
      }
      id++;
    }
  }
  cout<<ans<<endl;
  return 0;
}