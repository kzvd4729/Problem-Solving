/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/03/2020 18:29                        
*  solution_verdict: Wrong answer on test 18                 language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 13700 KB                             
*  problem: https://codeforces.com/contest/1428/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=5e5;
int a[N+2];
void no()
{
  cout<<-1<<endl,exit(0);
}
pair<int,int>rw[N+2],cl[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   vector<pair<int,int> >v;set<int>row,col;
  for(int i=n;i>=1;i--)
  {
    if(a[i]==0)continue;
    else if(a[i]==1)
    {
      v.push_back({i,i});
      rw[i]={i,i},cl[i]={i,i};
      row.insert(i);col.insert(i);
    }
    else if(a[i]==2)
    {
      if(row.size()==0)no();int x=*row.rbegin();
      v.push_back({x,i});row.erase(x);
      col.insert(i);col.erase(rw[x].second);
      cl[i]={x,i};
    }
    else
    {
      v.push_back({i,i});if(col.size()==0)no();
      int x=*col.rbegin();v.push_back({i,x});col.erase(x);
      col.insert(i);row.erase(cl[x].first);
      rw[i]={i,i};col.insert(i);
    }
    //cout<<endl;
    //for(auto x:v)cout<<x.first<<" "<<x.second<<endl;
    //cout<<"row ";for(auto x:row)cout<<x<<" ";cout<<endl;
    //cout<<"col ";for(auto x:col)cout<<x<<" ";cout<<endl;
  }
  cout<<v.size()<<'\n';
  for(auto x:v)cout<<x.first<<" "<<x.second<<'\n';
  return 0;
}