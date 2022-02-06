/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/18/2018 02:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1023/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int arr[N+2],lt[N+2],rt[N+2];
int vis[N+2],tmp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   for(int i=1;i<=N;i++)
    lt[i]=N;
   int n,q;cin>>n>>q;
  int zero=-1;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];tmp[i]=arr[i];
    if(arr[i])
    {
      lt[arr[i]]=min(lt[arr[i]],i);
      rt[arr[i]]=max(rt[arr[i]],i);
    }
    else zero=i;
  }
  if(zero==-1&&rt[q]==0)
    cout<<"NO"<<endl,exit(0);
  if(rt[q]==0)
  {
    arr[zero]=q;
    lt[q]=zero,rt[q]=zero;
  }
  for(int i=q;i>=1;i--)
  {
    for(int j=lt[i];j<=rt[i];j++)
    {
      if(arr[j]==i){}
      else if(arr[j]<i)
      {
        if(arr[j]==0)arr[j]=i;
        else cout<<"NO"<<endl,exit(0);
      }
      else j=rt[arr[j]];
    }
  }
  for(int i=1;i<=q;i++)
  {
    if(rt[i]==0)continue;
    int id=lt[i]-1;
    while(arr[id]==0&&id>0)arr[id--]=i;
    id=rt[i]+1;
    while(arr[id]==0&&id<=n)arr[id++]=i;
  }
  cout<<"YES"<<endl;
  for(int i=1;i<=n;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  return 0;
}