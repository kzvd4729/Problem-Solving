/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/15/2019 09:55                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1194/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4+1,C=5e3+1;
  int Pr[N+2],Rt[N+2],R;
struct Persistent
{
  int l,r,sm;
}Seg[N*20+2];
void Add(int node,int lo,int hi,int pnode,int id,int vl)
{
  if(lo==hi)
  {
    Seg[node].sm=Seg[pnode].sm+vl;return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)
  {
    Seg[node].l=++R;Seg[node].r=Seg[pnode].r;
    Add(Seg[node].l,lo,md,Seg[pnode].l,id,vl);
  }
  else
  {
    Seg[node].r=++R;Seg[node].l=Seg[pnode].l;
    Add(Seg[node].r,md+1,hi,Seg[pnode].r,id,vl);
  }
  Seg[node].sm=Seg[Seg[node].l].sm+Seg[Seg[node].r].sm;
}
int Find(int node,int lo,int hi,int vl)
{
  if(lo>=vl)return Seg[node].sm;
  if(hi<vl)return 0;
  int md=(lo+hi)/2;
  int p1=Find(Seg[node].l,lo,md,vl);
  int p2=Find(Seg[node].r,md+1,hi,vl);
  return p1+p2;
}
 int ver,hor;
struct vertical
{
  int a,b,c;
}vv[N+2];
struct horizontal
{
  int a,b,c;
}hh[N+2];
bool cmp(horizontal A,horizontal B)
{
  return A.c<B.c;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int a,b,c,d;cin>>a>>b>>c>>d;
    a+=C,b+=C,c+=C,d+=C;
    if(a==c)
      vv[++ver]={min(b,d),max(b,d),a};
    else 
      hh[++hor]={min(a,c),max(a,c),b};
  }
  //cout<<ver<<" --- "<<hor<<endl;
  sort(hh+1,hh+hor+1,cmp);long ans=0;
  for(int i=1;i<=ver;i++)
  {
    vector<int>v;v.push_back(0);
    for(int j=1;j<=hor;j++)
    {
      if(hh[j].c>=vv[i].a&&hh[j].c<=vv[i].b&&hh[j].a<=vv[i].c&&hh[j].b>=vv[i].c)
      {
        //cout<<"here"<<endl;
        int nd=hh[j].c;
        Rt[nd]=++R;Add(Rt[nd],1,N,Rt[v.back()],hh[j].b,1);
        v.push_back(nd);
      }
    }
    for(int j=1;j<=ver;j++)
    {
      if(vv[j].c<=vv[i].c)continue;
      int rt=upper_bound(v.begin(),v.end(),vv[j].b)-v.begin()-1;
      int lt=lower_bound(v.begin(),v.end(),vv[j].a)-v.begin()-1;
      int now=Find(Rt[v[rt]],1,N,vv[j].c)-Find(Rt[v[lt]],1,N,vv[j].c);
      ans+=((now*(now-1))/2);
    }
    for(int i=0;i<=R;i++)Seg[i].sm=0;
    R=0;
  }
cout<<ans<<endl;
  return 0;
}