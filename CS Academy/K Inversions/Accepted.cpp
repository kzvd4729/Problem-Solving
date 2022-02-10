/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 23 ms                                           memory_used: 1792 KB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,x,i,rv,ok,ex,now,arr[100005],cnt,nn;
void _find(void)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      if(arr[i]>arr[j])cnt++;
    }
  }
  cout<<cnt<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for(i=2;i<=n;i++)
  {
    long x=(i*(i-1))/2;
    if(x>k)break;
    rv=i;
  }
  ok=n-rv;
  ex=k-(rv*(rv-1))/2;
  int id=0;
  for(i=1;i<=ok;i++)
  {
    if(i==ok)arr[++id]=ok+ex;
    else arr[++id]=i;
  }
  now=n;
  nn=n;
  for(i=ok+1;i<=n;i++)
  {
    if(nn==ok+ex);
    else
    {
      if(now==ok+ex)now--;
      arr[++id]=now;
      now--;
    }
    nn--;
  }
  //cout<<id<<endl;
  if(id<n)arr[++id]=ok;
  for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
  cout<<endl;
  //_find();
  return 0;
}