/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/04/2020 19:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 420 ms                                          memory_used: 42200 KB                             
*  problem: https://codeforces.com/contest/1284/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=2e9;
vector<vector<int> >v;
 pair<int,int>mm[N+2];
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    mm[node]={v[lo][2],v[lo][3]};return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  mm[node].first=max(mm[node*2].first,mm[node*2+1].first);
  mm[node].second=min(mm[node*2].second,mm[node*2+1].second);
}
pair<int,int>get(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return {-inf,inf};
  if(lo>=lt&&hi<=rt)return mm[node];
  int md=(lo+hi)/2;
  pair<int,int>p1=get(node*2,lo,md,lt,rt);
  pair<int,int>p2=get(node*2+1,md+1,hi,lt,rt);
  pair<int,int>p;
  p.first=max(p1.first,p2.first);
  p.second=min(p1.second,p2.second);
  return p;
}
  long bit[2][N+2];
void upd(int x,long ml,long sm)
{
  for( ;x<=N;x+=(x&-x))
    bit[0][x]+=ml,bit[1][x]+=sm;
}
long get(int x)
{
  long ml=0,sm=0,bg=x;
  for( ;x>0;x-=(x&-x))
    ml+=bit[0][x],sm+=bit[1][x];
  return ml*bg+sm;
}
void range(int lo,int hi,long vl)
{
  upd(lo,vl,-vl*(lo-1));
  upd(hi,-vl,vl*hi);
}
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;v.resize(n);vector<int>com;
  for(int i=0;i<n;i++)
  {
    v[i].resize(4);
    for(int j=0;j<4;j++)
    {
      cin>>v[i][j];com.push_back(v[i][j]);
    }
  }
   //..................
  sort(com.begin(),com.end());
  com.erase(unique(com.begin(),com.end()),com.end());
  map<int,int>mp;int mx=com.size();
  for(int i=0;i<com.size();i++)
    mp[com[i]]=i+1;
  for(int i=0;i<v.size();i++)
  {
    for(int j=0;j<v[i].size();j++)
      v[i][j]=mp[v[i][j]];
  }
   sort(v.begin(),v.end());
   /*cout<<"//...................\n";
  for(auto x:v)
  {
    for(int i=0;i<x.size();i++)cout<<x[i]<<" ";
    cout<<endl;
  }*/
   build(1,0,n-1);
   vector<vector<int> >a;
  for(int i=0;i<n;i++)
  {
    vector<int>u={v[i][1],inf+1,inf+1,inf+1};
    int id=lower_bound(v.begin(),v.end(),u)-v.begin();
     int lt=i+1,rt=id-1;
    //cout<<i<<" "<<lt<<" "<<rt<<endl;
    if(lt<=rt)
    {
      pair<int,int>p=get(1,0,n-1,lt,rt);
      //cout<<p.first<<" --> "<<p.second<<endl;
      if(p.second<v[i][2]||p.first>v[i][3])cout<<"NO\n",exit(0);
    }
    if(id<n)a.push_back({id,v[i][2],v[i][3]});////
  }
  sort(a.begin(),a.end());
   int pt=a.size()-1;
  for(int i=v.size()-1;i>=0;i--)
  {
    range(v[i][2],v[i][3],1);
    while(pt>=0&&a[pt][0]==i)
    {
      int sm=get(a[pt][2]);
      if(a[pt][1]>1)sm-=get(a[pt][1]-1);
      if(sm)cout<<"NO\n",exit(0);
      pt--;
    }
  }
  cout<<"YES\n";
  return 0;
}