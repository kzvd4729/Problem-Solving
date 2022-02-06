/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/14/2018 12:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 5300 KB                              
*  problem: https://codeforces.com/contest/69/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
const int N=1e5;
using namespace std;
int n,k,arr[N+2],tmp;
map<int,int>mp;
set<int>st;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>arr[i];
   for(int i=1;i<=k;i++)
  {
    tmp=++mp[arr[i]];
    if(tmp==1)st.insert(arr[i]);
    else st.erase(arr[i]);
  }
  if(!st.size())cout<<"Nothing"<<endl;
  else cout<<*st.rbegin()<<endl;
  for(int i=k+1;i<=n;i++)
  {
    tmp=++mp[arr[i]];
    if(tmp==1)st.insert(arr[i]);
    else st.erase(arr[i]);
    tmp=--mp[arr[i-k]];
    if(tmp==1)st.insert(arr[i-k]);
    else st.erase(arr[i-k]);
    if(!st.size())cout<<"Nothing"<<endl;
    else cout<<*st.rbegin()<<endl;
  }
  return 0;
}