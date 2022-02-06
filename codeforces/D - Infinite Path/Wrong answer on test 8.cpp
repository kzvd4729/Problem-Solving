/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/10/2020 16:26                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 1216 ms                                         memory_used: 2200 KB                              
*  problem: https://codeforces.com/contest/1327/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long;
using namespace std;
const int N=2e5;
int n,cl[N+2];
vector<int>ml(vector<int>a,vector<int>b)
{
  vector<int>c(n+2);
  for(int i=1;i<=n;i++)c[i]=b[a[i]];
  return c;
}
vector<int>big(vector<int>a,int p)
{
  vector<int>r(n+2);for(int i=1;i<=n;i++)r[i]=i;
  while(p)
  {
    if(p%2)r=ml(r,a);
    a=ml(a,a);p/=2;
  }
  return r;
}
bool vis[N+2];
bool ck(vector<int>a)
{
  for(int i=1;i<=n;i++)vis[i]=0;
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    int x=i;vector<int>tmp;
    while(!vis[x])
    {
      tmp.push_back(x);
      vis[x]=1;x=a[x];
    }
    int f=0;
    for(int i=1;i<tmp.size();i++)
      if(cl[tmp[i]]!=cl[tmp[i-1]])f=1;
    if(f==0)return true;
  }
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n;vector<int>a(n+2);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>cl[i];
     int lo=1,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(ck(big(a,md)))hi=md;else lo=md;
    }
    int ans=n;
    for(md=lo;md<=hi;md++)
    {
      if(ck(big(a,md))){ans=md;break;}
    }
    for(int p=1;p<=ans;p+=p)
    {
      if(ck(big(a,p))){ans=p;break;} 
    }
    for(int p=1;p<=100;p++)
    {
      if(ck(big(a,p))){ans=p;break;} 
    }
    cout<<ans<<endl;
  }
  return 0;
}