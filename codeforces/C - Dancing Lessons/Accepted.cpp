/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/30/2018 03:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 545 ms                                          memory_used: 21600 KB                             
*  problem: https://codeforces.com/contest/45/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long n,arr[N+2],u,v,vnext,uprev;
string s;
set<pair<long,pair<long,long> > >st;
pair<long,pair<long,long> >p;
vector<pair<long,long> >ans;
struct linked_list
{
  long prev,next;
}link[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>s;
  s="#"+s;
  s+="#";
  for(int i=1;i<=n;i++)cin>>arr[i];
  for(int i=2;i<n;i++)link[i]={i-1,i+1};
  for(int i=1;i<=n;i++)
  {
    if(s[i]=='B'&&s[link[i].next]=='G')st.insert({abs(arr[i]-arr[link[i].next]),{i,link[i].next}});
    if(s[i]=='B'&&s[link[i].prev]=='G')st.insert({abs(arr[i]-arr[link[i].prev]),{link[i].prev,i}});
    if(s[i]=='G'&&s[link[i].next]=='B')st.insert({abs(arr[i]-arr[link[i].next]),{i,link[i].next}});
    if(s[i]=='G'&&s[link[i].prev]=='B')st.insert({abs(arr[i]-arr[link[i].prev]),{link[i].prev,i}});
  }
  while(st.size())
  {
    p=*st.begin();
    u=p.second.first;
    v=p.second.second;
    ans.push_back({u,v});
        uprev=link[u].prev;
    vnext=link[v].next;
        if(s[u]=='B'&&s[link[u].next]=='G')st.erase({abs(arr[u]-arr[link[u].next]),{u,link[u].next}});
    if(s[u]=='B'&&s[link[u].prev]=='G')st.erase({abs(arr[u]-arr[link[u].prev]),{link[u].prev,u}});
    if(s[u]=='G'&&s[link[u].next]=='B')st.erase({abs(arr[u]-arr[link[u].next]),{u,link[u].next}});
    if(s[u]=='G'&&s[link[u].prev]=='B')st.erase({abs(arr[u]-arr[link[u].prev]),{link[u].prev,u}});
        if(s[v]=='B'&&s[link[v].next]=='G')st.erase({abs(arr[v]-arr[link[v].next]),{v,link[v].next}});
    if(s[v]=='B'&&s[link[v].prev]=='G')st.erase({abs(arr[v]-arr[link[v].prev]),{link[v].prev,v}});
    if(s[v]=='G'&&s[link[v].next]=='B')st.erase({abs(arr[v]-arr[link[v].next]),{v,link[v].next}});
    if(s[v]=='G'&&s[link[v].prev]=='B')st.erase({abs(arr[v]-arr[link[v].prev]),{link[v].prev,v}});
        if(s[uprev]=='B'&&s[vnext]=='G')st.insert({abs(arr[uprev]-arr[vnext]),{uprev,vnext}});
    if(s[uprev]=='G'&&s[vnext]=='B')st.insert({abs(arr[uprev]-arr[vnext]),{uprev,vnext}});
        link[link[u].prev].next=vnext;
    link[link[v].next].prev=uprev;
   }
  cout<<ans.size()<<endl;
  for(auto x:ans)cout<<x.first<<" "<<x.second<<endl;
  return 0;
}