/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/19/2019 21:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1013 ms                                         memory_used: 88400 KB                             
*  problem: https://codeforces.com/contest/1141/problem/F2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
map<int,int>mp;
vector<pair<int,int> >po[N+N+2];
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n;cin>>n;vector<int>v;
 for(int i=1;i<=n;i++)
  cin>>aa[i];
 for(int i=1;i<=n;i++)
 {
  int sm=0;
  for(int j=i;j<=n;j++)
  {
   sm+=aa[j];
   v.push_back(sm);
  }
 }
 sort(v.begin(),v.end());
 v.erase(unique(v.begin(),v.end()),v.end());
 for(int i=0;i<v.size();i++)
  mp[v[i]]=i+1;
 for(int i=1;i<=n;i++)
 {
  int sm=0;
  for(int j=i;j<=n;j++)
  {
   sm+=aa[j];
   po[mp[sm]].push_back({i,j});
  }
 }
 n=v.size();int mx=0,id=-1;
 for(int i=1;i<=n;i++)
 {
  sort(po[i].begin(),po[i].end());
  int cnt=0,mn=1e9;
  for(int j=po[i].size()-1;j>=0;j--)
  {
   if(po[i][j].second<mn)
   {
    cnt++;mn=po[i][j].first;
   }
  }
  if(cnt>mx)
  {
   mx=cnt;id=i;
  }
 }
 cout<<mx<<endl;
 int cnt=0,mn=1e9;
 for(int j=po[id].size()-1;j>=0;j--)
 {
  if(po[id][j].second<mn)
  {
   mn=po[id][j].first;
   cout<<po[id][j].first<<" "<<po[id][j].second<<"\n";
  }
 }
 return 0;
}