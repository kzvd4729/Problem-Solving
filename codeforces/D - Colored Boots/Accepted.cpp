/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/19/2019 21:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 108 ms                                          memory_used: 8900 KB                              
*  problem: https://codeforces.com/contest/1141/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
set<int>on[30];
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n;cin>>n;string a,b;cin>>a>>b;
 for(int i=0;i<n;i++)
 {
  if(a[i]=='?')on[26].insert(i);
  else on[a[i]-'a'].insert(i);
 }
 vector<int>po,ex;vector<pair<int,int> >ans;
 for(int i=0;i<n;i++)
 {
  if(b[i]=='?')po.push_back(i);
  else
  {
   if(on[b[i]-'a'].size()>0)
   {
    int x=*on[b[i]-'a'].begin();
    ans.push_back({x,i});
    on[b[i]-'a'].erase(x);
   }
   else ex.push_back(i);
  }
 }
 while(true)
 {
  if(on[26].size()==0)break;
  if(ex.size()==0)break;
  int x=*on[26].begin();
  ans.push_back({x,ex.back()});
  ex.pop_back();on[26].erase(x);
 }
 ex.clear();
 for(int i=0;i<=26;i++)
 {
  while(on[i].size())
  {
   int x=*on[i].begin();
   ex.push_back(x);on[i].erase(x);
  }
 }
 while(true)
 {
  if(ex.size()==0||po.size()==0)break;
  ans.push_back({ex.back(),po.back()});
  ex.pop_back();po.pop_back();
 }
 cout<<ans.size()<<endl;
 for(auto x:ans)
  cout<<x.first+1<<" "<<x.second+1<<"\n";
 return 0;
}