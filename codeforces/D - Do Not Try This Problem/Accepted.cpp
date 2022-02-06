/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/16/2019 16:35                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 84500 KB                             
*  problem: https://codeforces.com/gym/102307/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int vis[N+2],lft[92][N+2],rgt[92][N+2],n;
vector<int>v[92];
map<pair<int,int>,int>mp;
int findLft(int i,int j)
{
  if(j==-1||lft[i][j]==j)return j;
  return lft[i][j]=findLft(i,lft[i][j]);
}
int findRgt(int i,int j)
{
  if(j==n||rgt[i][j]==j)return j;
  return rgt[i][j]=findRgt(i,rgt[i][j]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;n=s.size();
   int q;cin>>q;vector<vector<int> >qr;
  while(q--)
  {
    int i,a,k,c;char ch;cin>>i>>a>>k>>ch;c=(int)ch;
    int lt=i,rt=i+k*a;lt--,rt--;
    vector<int>v={lt,rt,a,c};
    qr.push_back(v);
  }
  int id=0;
  for(int i=1;i<=13;i++)
  {
    for(int j=0;j<i;j++)
    {
      for(int k=j;k<n;k+=i)
      {
        v[id].push_back(k);
      }
      mp[{i,j}]=id;
      id++;
    }
  }
  for(int i=0;i<id;i++)
    for(int j=0;j<n;j++)lft[i][j]=j,rgt[i][j]=j;
  while(qr.size())
  {
    vector<int>u=qr.back();qr.pop_back();
    int l=u[0],r=u[1],a=u[2],c=u[3];
    if(a>13)
    {
      for(int i=l;i<=r;i+=a)
        if(!vis[i])vis[i]=c;
      continue;
    }
    int id=mp[{a,l%a}];
    l=lower_bound(v[id].begin(),v[id].end(),l)-v[id].begin();
    r=lower_bound(v[id].begin(),v[id].end(),r)-v[id].begin();
     l=findRgt(id,l),r=findLft(id,r);
    if(l>r)continue;
    for(int i=l;i<=r;i++)
    {
      if(!vis[v[id][i]])vis[v[id][i]]=c;
      rgt[id][i]=r+1,lft[id][i]=l-1;
    }
  }
  for(int i=0;i<n;i++)
  {
    if(vis[i])cout<<(char)vis[i];
    else cout<<s[i];
  }
  cout<<endl;
  return 0;
}