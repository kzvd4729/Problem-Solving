/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/03/2018 17:29                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/766/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define endl "\n"
using namespace std;
const int N=1e5;
int col[N+2],par[N+2],par2[N+2];
map<string,int>mp;
int _find(int x)
{
  if(x==par[x])return x;
  return par[x]=_find(par[x]);
}
int _find2(int x)
{
  if(x==par2[x])return x;
  return par2[x]=_find2(par2[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,q;cin>>n>>m>>q;int cnt=0;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    mp[s]=++cnt;
  }
  for(int i=1;i<=n;i++)par[i]=i,par2[i]=i;
  while(m--)
  {
    int ty;string a,b;cin>>ty>>a>>b;
    int i=mp[a],j=mp[b];
    int ii=_find2(i),jj=_find2(j);
    par2[ii]=jj;
    if(ty==1)
    {
      int r1=_find(i),r2=_find(j);
      if(col[r1]&&col[r2])
      {
        if(col[r1]!=col[r2])
          cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        continue;
      }
      if(col[r1])par[r2]=r1;
      else if(col[r2])par[r1]=r2;
      else par[r1]=r2;
      cout<<"YES"<<endl;
    }
    else
    {
      int r1=_find(i),r2=_find(j);
      if(r1==r2)
      {
        cout<<"NO"<<endl;
        continue;
      }
      if(col[r1]&&col[r2])
      {
        if(col[r1]==col[r2])
          cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        continue;
      }
      else if(col[r1])
      {
        if(col[r1]==1)
          col[r2]=2;
        else col[r2]=1;
      }
      else if(col[r2])
      {
        if(col[r2]==1)
          col[r1]=2;
        else col[r1]=1;
      }
      else col[r1]=1,col[r2]=2;
      cout<<"YES"<<endl;
    }
  }
  while(q--)
  {
    string a,b;cin>>a>>b;
    int i=mp[a],j=mp[b];
    if(_find2(i)!=_find2(j))
    {
      cout<<3<<endl;continue;
    }
    int r1=_find(i),r2=_find(j);
    if(col[r1]==col[r2]||!col[r1]||!col[r2])
      cout<<1<<endl;
    else cout<<2<<endl;
  }
  return 0;
}