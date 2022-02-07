/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-18 16:43:27                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11995
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int ty[N+2],vl[N+2];
bool isStack(int n)
{
  stack<int>st;
  for(int i=1;i<=n;i++)
  {
    if(ty[i]==1)st.push(vl[i]);
    else
    {
      if(st.size()==0)return false;
      if(st.top()!=vl[i])return false;
      st.pop();
    }
  }
  return true;
}
bool isQueue(int n)
{
  queue<int>q;
  for(int i=1;i<=n;i++)
  {
    if(ty[i]==1)q.push(vl[i]);
    else
    {
      if(q.size()==0)return false;
      if(q.front()!=vl[i])return false;
      q.pop();
    }
  }
  return true;
}
bool isPQ(int n)
{
  priority_queue<int>pq;
  for(int i=1;i<=n;i++)
  {
    if(ty[i]==1)pq.push(vl[i]);
    else
    {
      if(pq.size()==0)return false;
      if(pq.top()!=vl[i])return false;
      pq.pop();
    }
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;while(cin>>n)
  {
    //if(n==-1)break;
    for(int i=1;i<=n;i++)cin>>ty[i]>>vl[i];
    int a=isStack(n),b=isQueue(n),c=isPQ(n);
    if(a&&!b&&!c)cout<<"stack\n";
    else if(!a&&b&&!c)cout<<"queue\n";
    else if(!a&&!b&&c)cout<<"priority queue\n";
    else if(!a&&!b&&!c)cout<<"impossible\n";
    else cout<<"not sure\n";
  }
  return 0;
}