/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/12/2018 17:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 561 ms                                          memory_used: 24900 KB                             
*  problem: https://codeforces.com/contest/733/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int a[N+2],b[N+2],c[N+2],mn,mx,one,two,twt,n;
map<pair<int,int>,pair<int,int> >mp;
void check(int aa,int bb,int cc,int id)
{
  if(mp.find({aa,bb})==mp.end())return ;
  pair<int,int>p=mp[{aa,bb}];
  mn=min(min(aa,bb),p.first+cc);
  if(mn>mx)
  {
    mx=mn;
    two=p.second;
    twt=id;
  }
}
void upd(int aa,int bb,int cc,int id)
{
  if(mp.find({aa,bb})==mp.end())
    mp[{aa,bb}]={cc,id};
  pair<int,int>p=mp[{aa,bb}];
  if(cc>p.first)mp[{aa,bb}]={cc,id};
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i]>>b[i]>>c[i];
    mn=min(min(a[i],b[i]),c[i]);
    if(mn>mx)
    {
      mx=mn;
      one=i;
    }
  }
  int mxx=mx;
  mx=0;
  for(int i=1;i<=n;i++)
  {
    check(a[i],b[i],c[i],i);
    check(a[i],c[i],b[i],i);
    check(b[i],a[i],c[i],i);
    check(b[i],c[i],a[i],i);
    check(c[i],a[i],b[i],i);
    check(c[i],b[i],a[i],i);
     upd(a[i],b[i],c[i],i);
    upd(a[i],c[i],b[i],i);
    upd(b[i],a[i],c[i],i);
    upd(b[i],c[i],a[i],i);
    upd(c[i],a[i],b[i],i);
    upd(c[i],b[i],a[i],i);
   }
  if(mxx>=mx)
    cout<<1<<endl<<one<<endl;
  else cout<<2<<endl<<two<<" "<<twt<<endl;
  return 0;
}