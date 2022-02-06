/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/25/2020 19:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1777 ms                                         memory_used: 70300 KB                             
*  problem: https://codeforces.com/contest/585/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#define long long long
using namespace std;
const int N=1e6;
int a[N+2],b[N+2],c[N+2],md,n;
map<pair<int,int>,int>mp;
map<pair<int,int>,vector<int> >pm;
void dfs1(int id,int i,int j,int k,int ma,int mb,int mc)
{
  if(id==md)
  {
    if(!mp.count({i-j,j-k}))
      mp[{i-j,j-k}]=i,pm[{i-j,j-k}]={ma,mb,mc};
    else if(i>mp[{i-j,j-k}])mp[{i-j,j-k}]=i,pm[{i-j,j-k}]={ma,mb,mc};
    return ;
  }
  dfs1(id+1,i+a[id],j+b[id],k,ma|(1<<id),mb|(1<<id),mc);
  dfs1(id+1,i+a[id],j,k+c[id],ma|(1<<id),mb,mc|(1<<id));
  dfs1(id+1,i,j+b[id],k+c[id],ma,mb|(1<<id),mc|(1<<id));
}
long ans=-1e18,fa,fb,fc;
void dfs2(int id,int i,int j,int k,int ma,int mb,int mc)
{
  if(id==n)
  {
    if(mp.count({j-i,k-j})&&(mp[{j-i,k-j}]*1LL+i)>ans)
    {
      ans=(mp[{j-i,k-j}]*1LL+i);
      fa=ma|pm[{j-i,k-j}][0];
      fb=mb|pm[{j-i,k-j}][1];
      fc=mc|pm[{j-i,k-j}][2];
    }
    return ;
  }
  dfs2(id+1,i+a[id],j+b[id],k,ma|(1<<id),mb|(1<<id),mc);
  dfs2(id+1,i+a[id],j,k+c[id],ma|(1<<id),mb,mc|(1<<id));
  dfs2(id+1,i,j+b[id],k+c[id],ma,mb|(1<<id),mc|(1<<id));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
  for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i];
   md=n/2;mp[{0,0}]=0;pm[{0,0}]={0,0,0};
  dfs1(0,0,0,0,0,0,0);dfs2(md,0,0,0,0,0,0);
  if(ans==-1e18)cout<<"Impossible\n",exit(0);
  for(int i=0;i<n;i++)
  {
    if(fa&(1<<i))cout<<'L';
    if(fb&(1<<i))cout<<'M';
    if(fc&(1<<i))cout<<'W';
    cout<<"\n";
  }
  return 0;
}