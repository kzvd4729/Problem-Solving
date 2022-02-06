/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/06/2020 12:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 11300 KB                             
*  problem: https://codeforces.com/contest/1326/problem/D2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
//od[i] is largest palindromic substring centered at i;
vector<int>od;
//ev[i] is largest palindromic substring centered at i and i+1;
vector<int>ev;
void manacher(string s)
{
  int n=s.size();
  od.resize(n);
  for(int i=0,l=0,r=-1;i<n;i++)
  {
    int k=(i>r)?1:min(od[l+r-i],r-i+1);
    while(0<=i-k&&i+k<n&&s[i-k]==s[i+k])k++;
    od[i]=k--;
    if(i+k>r)l=i-k,r=i+k;
  }
  ev.resize(n);
  for(int i=0,l=0,r=-1;i<n;i++)
  {
    int k=(i>r)?0:min(ev[l+r-i+1],r-i+1);
    while(0<=i-k-1&&i+k<n&&s[i-k-1]==s[i+k])k++;
    ev[i]=k--;
    if(i+k>r)l=i-k-1,r=i+k;
  }
  for(int i=0;i<n;i++)od[i]=od[i]*2-1;
  ev.erase(ev.begin());
  for(int i=0;i<n-1;i++)ev[i]=ev[i]*2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s,r;cin>>r;s=r;od.clear(),ev.clear();
    reverse(r.begin(),r.end());
    if(s==r)
    {
      cout<<s<<"\n";continue;
    }
    int pt=0;
    for(int i=0; ;i++)
    {
      if(s[i]==s[s.size()-1-i])pt++;
      else break;
    }
    r=s.substr(pt,s.size()-pt-pt);manacher(r);
    //cout<<r<<endl;
    int a=0,b=0;
    for(int i=0;i<r.size();i++)
    {
      if(i-od[i]/2==0)a=max(a,od[i]);
      if(i+od[i]/2==r.size()-1)b=max(b,od[i]);
    }
    for(int i=0;i<r.size()-1;i++)
    {
      if(i-ev[i]/2==-1)a=max(a,ev[i]);
      if(i+ev[i]/2==r.size()-1)b=max(b,ev[i]);
    }
    if(a>b)
    {
      for(int i=0;i<pt;i++)cout<<s[i];
      for(int i=0;i<a;i++)cout<<r[i];
      for(int i=pt-1;i>=0;i--)cout<<s[i];
      cout<<"\n";
    }
    else
    {
      reverse(r.begin(),r.end());
      for(int i=0;i<pt;i++)cout<<s[i];
      for(int i=0;i<b;i++)cout<<r[i];
      for(int i=pt-1;i>=0;i--)cout<<s[i];
      cout<<"\n";
    }
  }
  return 0;
}