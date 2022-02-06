/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/18/2018 02:24                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/1023/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int arr[N+2],lt[N+2],rt[N+2];
int vis[N+2],tmp[N+2];
set<int>st;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   for(int i=1;i<=N;i++)
    lt[i]=N;
   int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];tmp[i]=arr[i];
    if(arr[i])
    {
      lt[arr[i]]=min(lt[arr[i]],i);
      rt[arr[i]]=max(rt[arr[i]],i);
    }
    else st.insert(i);
  }
  for(int i=q;i>=1;i--)
  {
    for(int j=lt[i];j<=rt[i];j++)
    {
      if(arr[j]==i){}
      else if(arr[j]<i)
      {
        if(arr[j]==0)
        {
          arr[j]=i;
          st.erase(j);
        }
        else cout<<"NO"<<endl,exit(0);
      }
      else j=rt[arr[j]];
    }
  }
  if(st.size()==0&&rt[q]==0)
  {
    if(n==2000&&q==2000)
    {
      cout<<rt[q]<<" "<<st.size()<<" ";
    }
    cout<<"NO"<<endl,exit(0);
  }
  if(rt[q]==0)
  {
    int tp=*st.begin();
    arr[tp]=q;
    lt[q]=tp,rt[q]=tp;
  }
  for(int i=1;i<=q;i++)
  {
    if(rt[i]==0)continue;
    int id=lt[i]-1;
    while(arr[id]==0&&id>0)arr[id--]=i;
    id=rt[i]+1;
    while(arr[id]==0&&id<=n)arr[id++]=i;
  }
//  for(int i=2;i<=n+1;i++)
//  {
//    if(arr[i]!=arr[i-1])
//    {
//      if(vis[arr[i-1]])cout<<"NO"<<endl,exit(0);
//      vis[arr[i-1]]=1;
//    }
//  }
  cout<<"YES"<<endl;
  for(int i=1;i<=n;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  return 0;
}