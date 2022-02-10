/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Memory limit exceeded                   language: C++                                     
*  run_time: 1081 ms                                         memory_used: 256 MB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6+10;
//od[i] is largest palindromic substring centered at i;
vector<int>od;
//ev[i] is largest palindromic substring centered at i and i+1;
vector<int>ev;
void manachar(string s)
{
  string x="@#";
  for(auto c:s)x.push_back(c),x.push_back('#');
  x.push_back('$');s=x;
  int n=s.size();
  int l=0,r=0;vector<int>pp(n);
  for(int i=0;i<n;i++)
  {
    pp[i]=min(r-i,pp[l+r-i]);
    while(s[i-pp[i]]==s[i+pp[i]])pp[i]++;
    if(i+pp[i]>r)l=i-pp[i],r=i+pp[i];
  }
  for(int i=2;i<n-1;i+=2)od.push_back(pp[i]-1);
  for(int i=3;i<n-1;i+=2)ev.push_back(pp[i]-1);
}
/*
number of values greater than equal to x in prefix.
*/
struct persistent
{
  int l,r,sm;
}seg[N*24+2];
int rot[N+2],nw;
void upd(int node,int pnode,int lo,int hi,int id)
{
  if(lo==hi){seg[node].sm=seg[pnode].sm+1;return ;}
  int md=(lo+hi)/2;
  if(id<=md)
  {
    if(!seg[node].l)seg[node].l=++nw;upd(seg[node].l,seg[pnode].l,lo,md,id);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    if(!seg[node].r)seg[node].r=++nw;upd(seg[node].r,seg[pnode].r,md+1,hi,id);
    seg[node].l=seg[pnode].l;
  }
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
}
int get(int node,int lo,int hi,int vl)
{
  if(lo>=vl)return seg[node].sm;if(hi<vl)return 0;
  int md=(lo+hi)/2;
  return get(seg[node].l,lo,md,vl)+get(seg[node].r,md+1,hi,vl);
}
/*
void solve(int n)
{
  for(int i=1;i<=n;i++)
  {
    rot[i]=++nw;upd(rot[i],rot[i-1],1,n,aa[i]);
  }
}
*/
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;manachar(s);long ans=0;int n=s.size();
  for(int i=0;i<s.size()-1;i++)
  {
    ev[i]/=2;
    int l=i-ev[i],r=i-1;
    ans+=get(rot[r],0,n,i+1);
    if(l)ans-=get(rot[l-1],0,n,i+1);
    rot[i]=++nw;upd(rot[i],rot[i-1],0,n,i+1+ev[i]);
  }
  cout<<ans<<endl;
  return 0;
}