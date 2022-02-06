/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/16/2018 18:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1041/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int fr[N+2];
vector<pair<int,int> >ed;
struct data
{
  int x,y;
}arr[N+2];
bool cmp(data A,data B)
{
  return A.y<B.y;
}
void inv(void)
{
  cout<<"NO"<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    cin>>arr[i].x>>arr[i].y;
    if(arr[i].y>arr[i].x)swap(arr[i].x,arr[i].y);
    if(arr[i].x!=n)inv();
  }
  sort(arr+1,arr+n+1,cmp);
  for(int i=1;i<=n;i++)
    fr[arr[i].y]++;
  queue<int>q;
  for(int i=1;i<=n;i++)
  {
    if(!fr[i])q.push(i);
    else
    {
      int now=n;fr[i]--;
      if(q.size()<fr[i])inv();
      while(fr[i])
      {
        ed.push_back({now,q.front()});
        now=q.front();q.pop();
        fr[i]--;
      }
      ed.push_back({now,i});
    }
  }
  if(ed.size()!=n-1)inv();
  cout<<"YES"<<endl;
  for(auto x:ed)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}