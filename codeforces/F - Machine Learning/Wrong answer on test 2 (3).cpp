/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/03/2021 17:02                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 35600 KB                             
*  problem: https://codeforces.com/contest/940/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9;
 const int magic=300;
struct query
{
  int l,r,id;
}qr[N+2];
int a[N+2],blNo[N+2],p[N+2],vl[N+2],fr[N+2],ans[N+2];
map<int,int>frfr;
void add(int x,int f)
{
  //if(fr[x]<0)assert(0);
  frfr[fr[x]]--;
  fr[x]+=f;
  //if(fr[x]<0)assert(0);
  frfr[fr[x]]++;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,q;cin>>n>>q;vector<int>v;
  for(int i=1;i<=n;i++)cin>>a[i],v.push_back(a[i]);
   int cnt=0;
  for(int i=1;i<=q;i++)
  {
    int a,b,c;cin>>a>>b>>c;
    if(a==2)
    {
      v.push_back(c);p[i]=b,vl[i]=c;
    }
    else qr[++cnt]={b,c,i};
  }
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   map<int,int>mp;
  for(int i=1;i<=(int)v.size();i++)
    mp[v[i-1]]=i;
   for(int i=1;i<=n;i++)a[i]=mp[a[i]];
  for(int i=1;i<=q;i++)
    if(vl[i])vl[i]=mp[vl[i]];
   //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
  //for(int i=1;i<=q;i++)cout<<qr[i].r<<endl;
   for(int i=1;i<=n;i++)blNo[i]=i/magic;
  int bl=n/magic;
   sort(qr+1,qr+cnt+1,[&](query a,query b){
    if(blNo[a.l]==blNo[b.l]&&blNo[a.r]==blNo[b.r])
      return a.id<b.id;
    else if(blNo[a.l]==blNo[b.l])return a.r<b.r;
    else return a.l<b.l;
  });
   int l=1,r=0,id=0;
  for(int i=1;i<=cnt;i++)
  {
    for(int j=r+1;j<=qr[i].r;j++)add(a[j],1);
    for(int j=qr[i].l;j<l;j++)add(a[j],1);
    for(int j=l;j<qr[i].l;j++)add(a[j],-1);
    for(int j=qr[i].r+1;j<=r;j++)add(a[j],-1);
     while(id<qr[i].id)
    {
      id++;
      if(p[id])
      {
        add(vl[id],1);
        if(p[id]>=qr[i].id&&p[id]<=qr[i].id)add(a[p[id]],-1);
        int tmp=a[p[id]];
        a[p[id]]=vl[id];
         vl[id]=tmp;
      }
    }
    while(id>qr[i].id)
    {
      if(p[id])
      {
        add(vl[id],1);
        if(p[id]>=qr[i].id&&p[id]<=qr[i].id)add(a[p[id]],-1);
        int tmp=a[p[id]];
        a[p[id]]=vl[id];
         vl[id]=tmp;
      }
      id--;
    }
     for(int j=1; ;j++)
    {
      if(frfr[j]==0)
      {
        ans[i]=j;break;
      }
    }
    l=qr[i].l,r=qr[i].r;
  }
  for(int i=1;i<=cnt;i++)cout<<ans[i]<<" ";cout<<endl;
  return 0;
}