/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/09/2018 22:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/725/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=13;
int vis[10004],id,cy;
string s;
char ss[N+N+N+2],a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  for(int i=0;i<s.size();i++)
    ss[i+1]=s[i];
   for(int i=1;i<=27;i++)
  {
    if(vis[ss[i]])
    {
      id=vis[ss[i]];
      cy=i-vis[ss[i]]-1;
      break;
    }
    vis[ss[i]]=i;
  }
  if(cy==0)cout<<"Impossible"<<endl,exit(0);
   b[13-cy/2]=ss[id];
  int idd=id;
  for(int i=13-cy/2+1;i<=13;i++)
    b[i]=ss[++idd];
  int i;
  for(i=13;i>=1;i--)
  {
    ++idd;
    if(idd>27)break;
    if(ss[idd]==ss[id])++idd;
    if(idd>27)break;
    a[i]=ss[idd];
  }
  if(idd<27)
  {
    int ind=0;
    for(i=1;i<13-cy/2;i++)
    {
      if(idd<27)
      {
        b[i]=ss[++idd];
      }
      else b[i]=ss[++ind];
    }
  }
  else
  {
    int ind=0;
    for(int j=i;j>=1;j--)
      a[j]=ss[++ind];
    for(i=1;i<13-cy/2;i++)
      b[i]=ss[++ind];
  }
  for(int i=1;i<=13;i++)
    cout<<a[i];
  cout<<endl;
  for(int i=1;i<=13;i++)
    cout<<b[i];
  cout<<endl;
  return 0;
}